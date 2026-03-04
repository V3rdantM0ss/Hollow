package verdant_moss.hollow;

public record Version(int major, int minor, int build, int patch, ReleaseType type) {
	
	public String formatLong() {
		return major + "." + minor + "." + build + "." + patch + "-" + type.name();
	}
}
