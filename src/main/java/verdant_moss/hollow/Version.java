package verdant_moss.hollow;

/**
 * Represents the version of the project using a custom versioning scheme.
 *
 * <p>Version format:</p>
 * <pre>
 * major.minor.patch.build-type
 * </pre>
 *
 * <p>Example:</p>
 * <pre>
 * 1.2.0.15-BETA
 * </pre>
 *
 * <h2>Version number meaning</h2>
 *
 * <ul>
 *   <li><b>Major</b> – Large releases or complete overhauls.
 *   Typically used for the first release or major system changes.</li>
 *
 *   <li><b>Minor</b> – Important additions that expand the project
 *   but do not fundamentally change it (for example new systems,
 *   features, or regions).</li>
 *
 *   <li><b>Patch</b> – Bug fixes, balance changes, and small improvements.</li>
 *
 *   <li><b>Build</b> – Incremental builds used to quickly push updates.
 *   These builds may not be stable and mainly exist so changes are available.</li>
 * </ul>
 *
 * <h2>Release types</h2>
 *
 * <ul>
 *   <li><b>RELEASE</b> – Stable public version. Usually tied to a new
 *   major or minor version.</li>
 *
 *   <li><b>BETA</b> – Public testing version. Often used for experimental
 *   features or upcoming patches.</li>
 *
 *   <li><b>ALPHA</b> – Early development version intended for private
 *   testing with developers, friends, or testers. May contain major issues.</li>
 * </ul>
 */
public record Version(int major, int minor, int patch, int build, ReleaseType type) {
	/**
	 * Returns the full version string.
	 *
	 * @return formatted version string in the form
	 * major.minor.patch.build-TYPE
	 */
	public String formatLong() {
		return major + "." + minor + "." + patch + "." + build + "-" + type.name();
	}
}