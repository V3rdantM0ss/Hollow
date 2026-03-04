package verdant_moss.hollow;

import verdant_moss.hollow.aurora.Aurora;
import verdant_moss.hollow.aurora.LoggingLevel;

public class HollowTest {
	public static void main(String[] args) {
		Aurora.MinLevel = LoggingLevel.TRACE;
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.TRACE, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.DEBUG, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.SYSTEM, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.INFO, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.WARNING, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.ERROR, "Testing");
		Hollow.HOLLOW.get_aurora().log(LoggingLevel.FATAL, "Testing");
		Hollow.HOLLOW.get_aurora().trace("Short Testing");
		Hollow.HOLLOW.get_aurora().debug("Short Testing");
		Hollow.HOLLOW.get_aurora().system("Short Testing");
		Hollow.HOLLOW.get_aurora().info("Short Testing");
		Hollow.HOLLOW.get_aurora().warning("Short Testing");
		Hollow.HOLLOW.get_aurora().error("Short Testing");
		Hollow.HOLLOW.get_aurora().fatal("Short Testing");
	}
}