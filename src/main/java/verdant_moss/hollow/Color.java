package verdant_moss.hollow;

public class Color {
	public static final String RESET = "\u001B[0m";
	private int red, green, blue, alpha;
	
	public Color() {
	}
	
	public Color(int red, int green, int blue) {
		this.red = red;
		this.green = green;
		this.blue = blue;
		this.alpha = 255;
	}
	
	public String toAnsi() {
		return "\u001B[38;2;" + red + ";" + green + ";" + blue + "m";
	}
}
