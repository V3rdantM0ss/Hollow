/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#pragma once
#include "Version.hpp"
#include "Color.hpp"
#include "aurora/Aurora.hpp"
#include <string>

class Hollow {
private:
	const Version version;
	const std::string projectName;
	Color projectColor;
	mutable Aurora aurora;

public:
	Hollow(const Version& version, std::string projectName, const Color& projectColor);
	[[nodiscard]] const Version& getVersion() const;
	[[nodiscard]] const std::string& getProjectName() const;
	[[nodiscard]] const Color& getProjectColor() const;
	[[nodiscard]] Aurora& getAurora() const;
	[[nodiscard]] std::string getProjectInfo() const;
};
