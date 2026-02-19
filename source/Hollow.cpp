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
#include <locale>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/utsname.h>
#endif
const Version hollowVersion(0, 0, 0, 0, ReleaseType::ALPHA);
const std::string hollowName = "Hollow";
const Color hollowColor(143, 0, 255);
const Hollow hollow(hollowVersion, hollowName, hollowColor);
const Hollow* Hollow::internalHollow = nullptr;

Hollow::Hollow(const Version& version, std::string projectName, const Color& projectColor) : version(version),
	projectName(std::move(projectName)),
	projectColor(projectColor),
	aurora(*this) {
	if (!internalHollow) {
		internalHollow = this;
		logSystemInfo();
	}
}

Hollow::~Hollow() {
	if (internalHollow == this) {
		internalHollow = nullptr;
	}
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

void Hollow::logSystemInfo() {
	if (!internalHollow)
		return;
	Aurora& aurora = internalHollow->getAurora();
	aurora.system("=== System Information ===");
#ifdef _WIN32
	OSVERSIONINFOEX osvi; ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX)); osvi.dwOSVersionInfoSize = sizeof(
		OSVERSIONINFOEX); if (GetVersionEx((OSVERSIONINFO*)&osvi)) {
		aurora.system(
			"Operating System: Windows " + std::to_string(osvi.dwMajorVersion) + "." + std::to_string(
				osvi.dwMinorVersion));
	}
#else
	utsname unameData{};
	if (uname(&unameData) == 0) {
		aurora.system("Operating System: " + std::string(unameData.sysname) + " " + std::string(unameData.release));
	}
#endif
	const char* user = std::getenv("USER");
	if (const char* home = std::getenv("HOME"); user && home) {
		aurora.system("User: " + std::string(user) + " | Home: " + std::string(home));
	}
	try {
		const std::locale loc("");
		std::string localeName = loc.name();
		if (localeName == "C" || localeName.empty()) {
			const char* lang = std::getenv("LANG");
			if (const char* lc_all = std::getenv("LC_ALL"))
				localeName = lc_all;
			else if (lang)
				localeName = lang;
			else
				localeName = "Unknown";
		}
		if (localeName.find(';') != std::string::npos) {
			if (size_t start = localeName.find('='); start != std::string::npos) {
				start++;
				const size_t end = localeName.find(';', start);
				localeName = localeName.substr(start, end - start);
			}
		}
		aurora.system("Locale: " + localeName);
	}
	catch (...) {
		const char* lang = std::getenv("LANG");
		const char* lc_all = std::getenv("LC_ALL");
		std::string localeName = "Unknown";
		if (lc_all)
			localeName = lc_all;
		else if (lang)
			localeName = lang;
		if (localeName.find('.') != std::string::npos) {
			localeName = localeName.substr(0, localeName.find('.'));
		}
		aurora.system("Locale: " + localeName);
	}
	const std::time_t now = std::time(nullptr);
	if (const std::tm* localTime = std::localtime(&now)) {
		char tzBuf[32];
		std::strftime(tzBuf, sizeof(tzBuf), "%Z", localTime);
		aurora.system("Time Zone: " + std::string(tzBuf));
	}
	aurora.system("===========================");
}

Hollow& Hollow::getInternalHollow() {
	if (!internalHollow) {
		throw std::runtime_error("Internal Hollow instance not initialized");
	}
	return *const_cast<Hollow*>(internalHollow);
}
