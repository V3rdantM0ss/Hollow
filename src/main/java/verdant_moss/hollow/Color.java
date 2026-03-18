package verdant_moss.hollow;

public class Color {
	public static final String RESET = "\u001B[0m";
	public static final Color BLACK = new Color(0, 0, 0);
	public static final Color DARK_RED = new Color(128, 0, 0);
	public static final Color DARK_GREEN = new Color(0, 128, 0);
	public static final Color DARK_YELLOW = new Color(128, 128, 0);
	public static final Color DARK_BLUE = new Color(0, 0, 128);
	public static final Color DARK_MAGENTA = new Color(128, 0, 128);
	public static final Color DARK_CYAN = new Color(0, 128, 128);
	public static final Color LIGHT_GRAY = new Color(192, 192, 192);
	public static final Color GRAY = new Color(128, 128, 128);
	public static final Color RED = new Color(255, 0, 0);
	public static final Color GREEN = new Color(0, 255, 0);
	public static final Color YELLOW = new Color(255, 255, 0);
	public static final Color BLUE = new Color(0, 0, 255);
	public static final Color MAGENTA = new Color(255, 0, 255);
	public static final Color CYAN = new Color(0, 255, 255);
	public static final Color WHITE = new Color(255, 255, 255);
	public int red, green, blue, alpha;
	
	public Color() {
		this(0, 0, 0, 255);
	}
	
	public Color(int red, int green, int blue, int alpha) {
		this.red = red;
		this.green = green;
		this.blue = blue;
		this.alpha = alpha;
	}
	
	public Color(int red, int green, int blue) {
		this(red, green, blue, 255);
	}
	
	public String toAnsi() {
		return "\u001B[38;2;" + red + ";" + green + ";" + blue + "m";
	}
}