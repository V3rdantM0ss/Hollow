package verdant_moss.hollow;

import verdant_moss.hollow.aurora.LoggingLevel;

public class HollowTest {
	public static void main(String[] args) {
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.TRACE, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.DEBUG, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.SYSTEM, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.INFO, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.WARNING, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.ERROR, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.FATAL, "Testing");
	}
}