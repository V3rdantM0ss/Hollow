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
using hollow::Hollow;
using hollow::Aurora;
using hollow::LogLevel;

namespace hollow {
	class Hollow {
	private:
		const Version version;
		const std::string projectName;
		Color projectColor;
		mutable Aurora aurora;
		static const Hollow* hollow;

	public:
		Hollow(const Version& version, std::string projectName, const Color& projectColor);
		[[nodiscard]] const Version& getVersion() const;
		[[nodiscard]] const std::string& getProjectName() const;
		[[nodiscard]] const Color& getProjectColor() const;
		[[nodiscard]] Aurora& getAurora() const;
		[[nodiscard]] std::string getProjectInfo() const;
		static Hollow& getInternalHollow();
		static void logSystemInfo();
	};
}
