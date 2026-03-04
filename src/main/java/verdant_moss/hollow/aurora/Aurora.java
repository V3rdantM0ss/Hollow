package verdant_moss.hollow.aurora;

import verdant_moss.hollow.Color;
import verdant_moss.hollow.Version;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Aurora {
	public static LoggingLevel MinLevel = LoggingLevel.SYSTEM;
	private final String name;
	private final Version version;
	private final Color color;
	
	public Aurora(String name, Version version, Color color) {
		this.name = name;
		this.version = version;
		this.color = color;
	}
	
	public void debug(Object debug) {
		log(LoggingLevel.DEBUG, debug);
	}
	
	public void error(Object error) {
		log(LoggingLevel.ERROR, error);
	}
	
	public void fatal(Object fatal) {
		log(LoggingLevel.FATAL, fatal);
	}
	
	public void info(Object info) {
		log(LoggingLevel.INFO, info);
	}
	
	public void system(Object system) {
		log(LoggingLevel.SYSTEM, system);
	}
	
	public void trace(Object trace) {
		log(LoggingLevel.TRACE, trace);
	}
	
	public void log(LoggingLevel level, Object message) {
		if(MinLevel.ordinal() > level.ordinal()) {
			return;
		}
		String dateTimeSection = getDateTimeSection(level);
		String projectName = getProjectNameSection();
		String levelSection = getLevelSection(level);
		String messageSection = getMessageSection(level, message);
		System.out.println(dateTimeSection + projectName + levelSection + ": " + messageSection);
	}
	
	private String getDateTimeSection(LoggingLevel level) {
		LocalDateTime dateTime = LocalDateTime.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss|dd.MM.yyyy");
		return level.toAnsi() + "[" + dateTime.format(formatter) + "]" + Color.RESET;
	}
	
	private String getProjectNameSection() {
		return color.toAnsi() + "[" + name + "(" + version.formatLong() + ")]" + Color.RESET;
	}
	
	private String getLevelSection(LoggingLevel level) {
		return level.toAnsi() + "[" + level.evenSpaces() + "]" + Color.RESET;
	}
	
	private String getMessageSection(LoggingLevel level, Object message) {
		return level.toAnsi() + message.toString() + Color.RESET;
	}
	
	public void warning(Object warning) {
		log(LoggingLevel.WARNING, warning);
	}
}
