package verdant_moss.hollow;

import verdant_moss.hollow.aurora.Aurora;
import verdant_moss.hollow.aurora.LoggingLevel;

import static verdant_moss.hollow.Hollow.HOLLOW_AURORA;

public class HollowTest {
	public static void main(String[] args) {
		Aurora.MinLevel = LoggingLevel.TRACE;
		HOLLOW_AURORA.log(LoggingLevel.TRACE, "Testing");
		HOLLOW_AURORA.log(LoggingLevel.DEBUG, "Testing");
		HOLLOW_AURORA.log(LoggingLevel.SYSTEM, "Testing");
		HOLLOW_AURORA.log(LoggingLevel.INFO, "Testing");
		HOLLOW_AURORA.log(LoggingLevel.WARNING, "Testing");
		HOLLOW_AURORA.log(LoggingLevel.ERROR, "Testing");
		HOLLOW_AURORA.log(LoggingLevel.FATAL, "Testing");
		HOLLOW_AURORA.trace("Short Testing");
		HOLLOW_AURORA.debug("Short Testing");
		HOLLOW_AURORA.system("Short Testing");
		HOLLOW_AURORA.info("Short Testing");
		HOLLOW_AURORA.warning("Short Testing");
		HOLLOW_AURORA.error("Short Testing");
		HOLLOW_AURORA.fatal("Short Testing");
	}
}