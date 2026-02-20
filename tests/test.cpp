/*
* Hollow - A lightweight C++ core library
 * Copyright (c) 2026 VerdantMoss
 *
 * Licensed under the MIT License. See LICENSE file for details.
 *
 * Code Style: Import style.xml for JetBrains IDE formatting
 */
#include <iostream>
#include "Hollow.hpp"

int main() {
	const hollow::Version testVersion = hollow::Hollow::getInternalHollow().getVersion();
	const hollow::Color testColor(255, 255, 255);
	const std::string testName = "Test";
	const hollow::Hollow testHollow(testVersion, testName, testColor);
	const hollow::Aurora testAurora = testHollow.getAurora();
	const hollow::Hollow teeeest2(testVersion, "Teeeeeee2", testColor);
	const hollow::Aurora testAuroraTWO = teeeest2.getAurora();
	hollow::Aurora::setGlobalMinLevel(hollow::LogLevel::TRACE);
	testAurora.trace("Uhhh tracing stuff ig?");
	testAurora.debug("Wawa! A spooder :3 May i keep it?");
	testAuroraTWO.system("COOKIESSS GIMME!");
	testAurora.info("Wawa just wanted to inform you that i request a coffee");
	testAurora.warning("I didnt have my coffee yet im going to die");
	testAuroraTWO.error("*goo.exe stopped working*");
	testAurora.fatal("*KLNJHRLKJWNBJKRNOPONBÖJWQLNJBLWÖBJQ RÖLJBWR*");
	return 0;
}
