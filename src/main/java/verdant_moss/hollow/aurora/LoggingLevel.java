package verdant_moss.hollow.aurora;

import verdant_moss.hollow.Color;

public enum LoggingLevel {
	TRACE(0, 255, 255),
	DEBUG(255, 255, 255),
	SYSTEM(0, 255, 0),
	INFO(0, 0, 255),
	WARNING(255, 255, 0),
	ERROR(255, 0, 0),
	FATAL(255, 0, 255);
	private final Color color;
	
	LoggingLevel(int red, int green, int blue) {
		color = new Color(red, green, blue);
	}
	
	public String evenSpaces() {
		switch(this) {
			case TRACE -> {
				return "Trace  ";
			}
			case DEBUG -> {
				return "Debug  ";
			}
			case SYSTEM -> {
				return "System ";
			}
			case INFO -> {
				return "Info   ";
			}
			case WARNING -> {
				return "Warning";
			}
			case ERROR -> {
				return "Error  ";
			}
			case FATAL -> {
				return "Fatal  ";
			}
		}
		return "False";
	}
	
	public String toAnsi() {
		return color.toAnsi();
	}
}
