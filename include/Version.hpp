/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#pragma once
#include <string>

enum class ReleaseType {
	STABLE = 0,
	BETA = 1,
	ALPHA = 2
};

class Version {
private:
	int major, minor, patch, build;
	ReleaseType releaseType;

public:
	Version(int major, int minor, int patch, int build, ReleaseType releaseType) : major(major),
		minor(minor),
		patch(patch),
		build(build),
		releaseType(releaseType) {
	}

	[[nodiscard]] int getMajor() const;
	[[nodiscard]] int getMinor() const;
	[[nodiscard]] int getPatch() const;
	[[nodiscard]] int getBuild() const;
	[[nodiscard]] ReleaseType getReleaseType() const;
	[[nodiscard]] std::string toString() const;
	[[nodiscard]] std::string toShortString() const;
	bool operator>(const Version& other) const;
	bool operator<(const Version& other) const;
	bool operator==(const Version& other) const;
};
