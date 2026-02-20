/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#include "Version.hpp"
#include <sstream>

namespace hollow {
	int Version::getMajor() const {
		return major;
	}

	int Version::getMinor() const {
		return minor;
	}

	int Version::getPatch() const {
		return patch;
	}

	int Version::getBuild() const {
		return build;
	}

	ReleaseType Version::getReleaseType() const {
		return releaseType;
	}

	std::string Version::toString() const {
		std::ostringstream oss;
		oss << major << "." << minor << "." << patch << "." << build;
		switch (releaseType) {
			case ReleaseType::STABLE:
				oss << "";
				break;
			case ReleaseType::BETA:
				oss << "b";
				break;
			case ReleaseType::ALPHA:
				oss << "a";
				break;
		}
		return oss.str();
	}

	std::string Version::toShortString() const {
		std::ostringstream oss;
		oss << major << "." << minor << "." << patch;
		switch (releaseType) {
			case ReleaseType::STABLE:
				oss << "r";
				break;
			case ReleaseType::BETA:
				oss << "b";
				break;
			case ReleaseType::ALPHA:
				oss << "a";
				break;
		}
		return oss.str();
	}

	bool Version::operator>(const Version& other) const {
		if (major != other.major)
			return major > other.major;
		if (minor != other.minor)
			return minor > other.minor;
		if (patch != other.patch)
			return patch > other.patch;
		if (build != other.build)
			return build > other.build;
		return releaseType < other.releaseType;
	}

	bool Version::operator<(const Version& other) const {
		return other > *this;
	}

	bool Version::operator==(const Version& other) const {
		return major == other.major && minor == other.minor && patch == other.patch && build == other.build &&
			releaseType == other.releaseType;
	}
}
