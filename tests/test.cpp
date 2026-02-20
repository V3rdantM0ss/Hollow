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
using namespace hollow;

int main() {
	const Version testVersion = Hollow::getInternalHollow().getVersion();
	const Color testColor(255, 255, 255);
	const std::string testName = "Test";
	const Hollow testHollow(testVersion, testName, testColor);
	const Aurora testAurora = testHollow.getAurora();
	const Hollow teeeest2(testVersion, "Teeeeeee2", testColor);
	const Aurora testAuroraTWO = teeeest2.getAurora();
	Aurora::setGlobalMinLevel(LogLevel::TRACE);
	testAurora.trace("Uhhh tracing stuff ig?");
	testAurora.debug("Wawa! A spooder :3 May i keep it?");
	testAuroraTWO.system("COOKIESSS GIMME!");
	testAurora.info("Wawa just wanted to inform you that i request a coffee");
	testAurora.warning("I didnt have my coffee yet im going to die");
	testAuroraTWO.error("*goo.exe stopped working*");
	testAurora.fatal("*KLNJHRLKJWNBJKRNOPONBÖJWQLNJBLWÖBJQ RÖLJBWR*");
	return 0;
}
