/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#pragma once
#include <cstdint>
#include <string>

namespace hollow {
	class Color {
		public:
			Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
			Color(int r, int g, int b, int a = 255);
			[[nodiscard]] uint8_t getRed() const;
			[[nodiscard]] uint8_t getGreen() const;
			[[nodiscard]] uint8_t getBlue() const;
			[[nodiscard]] uint8_t getAlpha() const;
			void setRed(uint8_t red);
			void setGreen(uint8_t green);
			void setBlue(uint8_t blue);
			void setAlpha(uint8_t alpha);
			[[nodiscard]] std::string toString() const;
			[[nodiscard]] std::string toHex() const;
			[[nodiscard]] std::string toAnsiForeground() const;
			[[nodiscard]] std::string toAnsiBackground() const;
			static bool isValidColorValue(int value);

		private:
			uint8_t r, g, b, a;
	};
}
