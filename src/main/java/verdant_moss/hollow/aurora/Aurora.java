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
	
	public void log(LoggingLevel level, Object message) {
		if(MinLevel.ordinal() > level.ordinal()) {
			return;
		}
		String dateTimeSection = getDateTimeSection(level);
		String projectName = getProjectNameSection();
		String levelSection = getLevelSection(level);
		String messageSection = getMessageSection(level, message);
		StringBuilder messageChunk = new StringBuilder();
		messageChunk.append(dateTimeSection).append(projectName).append(levelSection).append(": ").append(messageSection);
		System.out.println(messageChunk);
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
}
