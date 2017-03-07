// This file is isolated to improve tests compilation speed
// See: https://github.com/philsquared/Catch/blob/master/docs/slow-compiles.md

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "bitboard.h"

int main(int argc, char* argv[]) {

	// Init engine modules
	Bitboards::init();
	
	// Run Catch session
	int result = Catch::Session().run(argc, argv);
	
	return result < 0xFF ? result : 0xFF;
}