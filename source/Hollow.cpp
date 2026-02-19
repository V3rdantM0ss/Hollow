/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#include "Hollow.hpp"
#include <utility>

Hollow::Hollow(const Version& version, std::string projectName, const Color& projectColor) : version(version),
	projectName(std::move(projectName)),
	projectColor(projectColor),
	aurora(*this) {
}

const Version& Hollow::getVersion() const {
	return version;
}

const std::string& Hollow::getProjectName() const {
	return projectName;
}

const Color& Hollow::getProjectColor() const {
	return projectColor;
}

Aurora& Hollow::getAurora() const {
	return aurora;
}

std::string Hollow::getProjectInfo() const {
	return projectName + " (" + version.toString() + ")";
}
