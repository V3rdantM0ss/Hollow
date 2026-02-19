/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#include <chrono>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Hollow.hpp"
#include "Aurora.hpp"
LogLevel Aurora::globalMinLevel = LogLevel::SYSTEM;

Aurora::Aurora(const Hollow& hollow) : hollow(hollow) {
}

void Aurora::setGlobalMinLevel(const LogLevel level) {
	globalMinLevel = level;
}

LogLevel Aurora::getGlobalMinLevel() {
	return globalMinLevel;
}

bool Aurora::shouldLog(LogLevel level) {
	return static_cast<int>(level) >= static_cast<int>(globalMinLevel);
}

Color Aurora::getLevelColor(const LogLevel level) {
	switch (level) {
	case LogLevel::TRACE: {
		return Color(0, 255, 255);
	}
	case LogLevel::DEBUG: {
		return Color(255, 255, 255);
	}
	case LogLevel::SYSTEM: {
		return Color(0, 255, 0);
	}
	case LogLevel::INFO: {
		return Color(0, 0, 255);
	}
	case LogLevel::WARNING: {
		return Color(255, 255, 0);
	}
	case LogLevel::ERROR: {
		return Color(255, 0, 0);
	}
	case LogLevel::FATAL: {
		return Color(255, 0, 255);
	}
	default: {
		return Color(255, 255, 255);
	}
	}
}

std::string Aurora::getCurrentTimestamp() {
	const auto now = std::chrono::system_clock::now();
	const auto time_t = std::chrono::system_clock::to_time_t(now);
	std::ostringstream oss;
	oss << std::put_time(std::localtime(&time_t), "%d.%m.%Y|%H.%M.%S");
	return oss.str();
}

std::string Aurora::formatMessage(const LogLevel level, const std::string& message) const {
	std::string levelName;
	switch (level) {
	case LogLevel::TRACE: {
		levelName = "TRACE";
		break;
	}
	case LogLevel::DEBUG: {
		levelName = "DEBUG";
		break;
	}
	case LogLevel::SYSTEM: {
		levelName = "SYSTEM";
		break;
	}
	case LogLevel::INFO: {
		levelName = "INFO";
		break;
	}
	case LogLevel::WARNING: {
		levelName = "WARNING";
		break;
	}
	case LogLevel::ERROR: {
		levelName = "ERROR";
		break;
	}
	case LogLevel::FATAL: {
		levelName = "FATAL";
		break;
	}
	default: {
		levelName = "UNKNOWN";
		break;
	}
	}
	Color levelColor = getLevelColor(level);
	Color projectColor = hollow.getProjectColor();
	std::ostringstream oss;
	oss << levelColor.toAnsiForeground() << "[" << getCurrentTimestamp() << "]";
	oss << projectColor.toAnsiForeground() << "[" << hollow.getProjectInfo() << "]";
	oss << levelColor.toAnsiForeground() << "[" << levelName << "]";
	oss << "\033[0m: ";
	oss << levelColor.toAnsiForeground() << message << "\033[0m";
	return oss.str();
}

void Aurora::log(LogLevel level, const std::string& message) const {
	if (shouldLog(level)) {
		std::cout << formatMessage(level, message) << std::endl;
	}
}

void Aurora::trace(const std::string& message) const {
	if (shouldLog(LogLevel::TRACE)) {
		log(LogLevel::TRACE, message);
	}
}

void Aurora::debug(const std::string& message) const {
	if (shouldLog(LogLevel::DEBUG)) {
		log(LogLevel::DEBUG, message);
	}
}

void Aurora::system(const std::string& message) const {
	if (shouldLog(LogLevel::SYSTEM)) {
		log(LogLevel::SYSTEM, message);
	}
}

void Aurora::info(const std::string& message) const {
	if (shouldLog(LogLevel::INFO)) {
		log(LogLevel::INFO, message);
	}
}

void Aurora::warning(const std::string& message) const {
	if (shouldLog(LogLevel::WARNING)) {
		log(LogLevel::WARNING, message);
	}
}

void Aurora::error(const std::string& message) const {
	if (shouldLog(LogLevel::ERROR)) {
		log(LogLevel::ERROR, message);
	}
}

void Aurora::fatal(const std::string& message) const {
	if (shouldLog(LogLevel::FATAL)) {
		log(LogLevel::FATAL, message);
	}
}
