/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#include "Color.hpp"
#include <sstream>
#include <stdexcept>
#include <iomanip>

Color::Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) : r(r), g(g), b(b), a(a) {
}

Color::Color(const int r, const int g, const int b, const int a) {
	if (!isValidColorValue(r) || !isValidColorValue(g) || !isValidColorValue(b) || !isValidColorValue(a)) {
		throw std::invalid_argument("Color values must be between 0 and 255");
	}
	this->r = static_cast<uint8_t>(r);
	this->g = static_cast<uint8_t>(g);
	this->b = static_cast<uint8_t>(b);
	this->a = static_cast<uint8_t>(a);
}

uint8_t Color::getRed() const {
	return r;
}

uint8_t Color::getGreen() const {
	return g;
}

uint8_t Color::getBlue() const {
	return b;
}

uint8_t Color::getAlpha() const {
	return a;
}

void Color::setRed(uint8_t red) {
	r = red;
}

void Color::setGreen(uint8_t green) {
	g = green;
}

void Color::setBlue(uint8_t blue) {
	b = blue;
}

void Color::setAlpha(uint8_t alpha) {
	a = alpha;
}

std::string Color::toString() const {
	std::ostringstream oss;
	oss << "rgba(" << static_cast<int>(r) << ", " << static_cast<int>(g) << ", " << static_cast<int>(b) << ", " <<
		static_cast<int>(a) << ")";
	return oss.str();
}

std::string Color::toHex() const {
	std::ostringstream oss;
	oss << "#" << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast<int>(r) << std::setw(2)
		<< static_cast<int>(g) << std::setw(2) << static_cast<int>(b) << std::setw(2) << static_cast<int>(a);
	return oss.str();
}

std::string Color::toAnsiForeground() const {
	std::ostringstream oss;
	oss << "\033[38;2;" << static_cast<int>(r) << ";" << static_cast<int>(g) << ";" << static_cast<int>(b) << "m";
	return oss.str();
}

std::string Color::toAnsiBackground() const {
	std::ostringstream oss;
	oss << "\033[48;2;" << static_cast<int>(r) << ";" << static_cast<int>(g) << ";" << static_cast<int>(b) << "m";
	return oss.str();
}

bool Color::isValidColorValue(int value) {
	return value >= 0 && value <= 255;
}
