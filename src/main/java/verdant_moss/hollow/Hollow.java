package verdant_moss.hollow;

import verdant_moss.hollow.aurora.Aurora;

public class Hollow {
	public static final String HOLLOW_NAME = "Hollow";
	public static final Version HOLLOW_VERSION = new Version(0, 0, 1, 3, ReleaseType.ALPHA);
	public static final Color HOLLOW_COLOR = new Color(101, 0, 179);
	public static final Hollow HOLLOW = new Hollow(HOLLOW_NAME, HOLLOW_VERSION, HOLLOW_COLOR);
	private final String name;
	private final Version version;
	private final Color color;
	private final Aurora aurora;
	
	public Hollow(String name, Version version, Color color) {
		this.name = name;
		this.version = version;
		this.color = color;
		aurora = new Aurora(name, version, color);
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
}
