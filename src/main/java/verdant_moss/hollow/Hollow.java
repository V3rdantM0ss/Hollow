package verdant_moss.hollow;

import verdant_moss.hollow.aurora.Aurora;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Locale;

/**
 * The central class of the Hollow library.
 *
 * <p>
 * Hollow serves mainly as a container for the {@link Aurora} logger and the versioning
 * information.
 * </p>
 */
public class Hollow {
	public static final String HOLLOW_NAME = "Hollow";
	public static final Version HOLLOW_VERSION = new Version(0, 1, 0, 0, ReleaseType.RELEASE);
	public static final Color HOLLOW_COLOR = new Color(101, 0, 179);
	public static final Hollow HOLLOW = new Hollow(HOLLOW_NAME, HOLLOW_VERSION, HOLLOW_COLOR);
	public static final Aurora HOLLOW_AURORA = HOLLOW.get_aurora();
	private final String name;
	private final Version version;
	private final Color color;
	private final Aurora aurora;
	
	public Hollow(String name, Version version, Color color) {
		this.name = name;
		this.version = version;
		this.color = color;
		this.aurora = new Aurora(name, version, color);
	}
	
	/**
	 * Logs system information at startup.
	 */
	private static void logStartupInfo() {
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH.mm.ss-dd.MM.yyyy");
		String timestamp = LocalDateTime.now().format(formatter);
		HOLLOW_AURORA.system("=== Hollow System Information ===");
		HOLLOW_AURORA.system("Time: " + timestamp);
		HOLLOW_AURORA.system("OS: " + System.getProperty("os.name") + " " + System.getProperty("os.version"));
		HOLLOW_AURORA.system("Locale: " + Locale.getDefault());
		HOLLOW_AURORA.system("===========================");
	}
	
	public Aurora get_aurora() {
		return aurora;
	}
	
	public String get_name() {
		return name;
	}
	
	public Version get_version() {
		return version;
	}
	
	public Color get_color() {
		return color;
	}
	
	static {
		logStartupInfo();
	}
}