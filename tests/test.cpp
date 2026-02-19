/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#include <iostream>
#include "Color.hpp"
#include "Hollow.hpp"
#include "Version.hpp"

int main() {
	const Version v(0, 1, 0, 0, ReleaseType::ALPHA);
	const Hollow hollow(v, "Hollow", Color(150, 50, 150));
	const Aurora& hollowAurora = hollow.getAurora();
	Aurora::setGlobalMinLevel(LogLevel::TRACE);
	hollowAurora.trace("Uhhh tracing stuff ig?");
	hollowAurora.debug("Wawa! A spooder :3 May i keep it?");
	hollowAurora.system("COOKIESSS GIMME!");
	hollowAurora.info("Wawa just wanted to inform you that i request a coffee");
	hollowAurora.warning("I didnt have my coffee yet im going to die");
	hollowAurora.error("*goo.exe stopped working*");
	hollowAurora.fatal("*KLNJHRLKJWNBJKRNOPONBÖJWQLNJBLWÖBJQ RÖLJBWR*");
	return 0;
}
