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
#include <iomanip>
#include "../Color.hpp"
class Hollow;

enum class LogLevel {
	TRACE,
	DEBUG,
	SYSTEM,
	INFO,
	WARNING,
	ERROR,
	FATAL
};

class Aurora {
	const Hollow& hollow;
	static LogLevel globalMinLevel;
	static bool systemInfoLogged;
	static Color getLevelColor(LogLevel level);
	static std::string getCurrentTimestamp();
	[[nodiscard]] std::string formatMessage(LogLevel level, const std::string& message) const;

public:
	explicit Aurora(const Hollow& hollow);
	static void setGlobalMinLevel(LogLevel level);
	static LogLevel getGlobalMinLevel();
	static bool shouldLog(LogLevel level);
	static void logSystemInfo(const Hollow& hollow);
	void log(LogLevel level, const std::string& message) const;
	void trace(const std::string& message) const;
	void debug(const std::string& message) const;
	void system(const std::string& message) const;
	void info(const std::string& message) const;
	void warning(const std::string& message) const;
	void error(const std::string& message) const;
	void fatal(const std::string& message) const;
};
