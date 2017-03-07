// Unit tests for the engine

#include "catch.hpp"

#include "types.h"
#include "position.h"
#include "bitboard.h"
#include "move.h"
#include "uci.h"

/****************** Position test cases *****************/

TEST_CASE("Initialize empty position", "[position]") {
	Position p;
	
	REQUIRE(p.getAllPieces() == 0);
	REQUIRE(p.getPieceSet(PAWN) == 0);
	REQUIRE(p.getPieceSet(KNIGHT) == 0);
	REQUIRE(p.getPieceSet(BISHOP) == 0);
	REQUIRE(p.getPieceSet(ROOK) == 0);
	REQUIRE(p.getPieceSet(QUEEN) == 0);
	REQUIRE(p.getPieceSet(KING) == 0);
	
	for (Square sq = A1; sq <= H8; sq++) {
		CAPTURE(sq);
		REQUIRE(p.getPieceAt(sq) == NO_PIECE);
	}
}

TEST_CASE("Position set with FEN string", "[position]") {
	Position p;
	
	SECTION("Pieces position in the board with starting FEN") {
		p.set(UCI::startingFEN);
		
		REQUIRE(p.getAllPieces() == 0xFFFF00000000FFFF);
		REQUIRE(p.getPieceSet(PAWN) == 0x00FF00000000FF00);
		REQUIRE(p.getPieceSet(KNIGHT) == 0x4200000000000042);
		REQUIRE(p.getPieceSet(BISHOP) == 0x2400000000000024);
		REQUIRE(p.getPieceSet(ROOK) == 0x8100000000000081);
		REQUIRE(p.getPieceSet(QUEEN) == 0x0800000000000008);
		REQUIRE(p.getPieceSet(KING) == 0x1000000000000010);
	}
	
}
/********************************************************/

/****************** Bitboard test cases *****************/

TEST_CASE("Mask rank", "[bitboard]") {
	
	SECTION("Between limit values") {
		
		INFO("Rank 1");
		Bitboard expect = 0xFF;
		REQUIRE(Bitboards::maskRank(RANK_1) == expect);
		
		INFO("Rank 8");
		expect = 0xFF00000000000000;
		REQUIRE(Bitboards::maskRank(RANK_8) == expect);
	}
	
	SECTION("Out of limits") {
		REQUIRE(Bitboards::maskRank(NO_RANK) == 0);
	}
}

TEST_CASE("Mask file", "[bitboard]") {
	
	SECTION("Between limit values") {
		
		INFO("File A");
		Bitboard expect = 0x0101010101010101;
		REQUIRE(Bitboards::maskFile(FILE_A) == expect);
		
		INFO("File H");
		expect = 0x8080808080808080;
		REQUIRE(Bitboards::maskFile(FILE_H) == expect);
	}
	
	SECTION("Out of limits") {
		REQUIRE(Bitboards::maskFile(NO_FILE) == 0);
	}
}

TEST_CASE("Clear rank", "[bitboard]") {
	
	SECTION("Between limit values") {
		
		INFO("Rank 1");
		Bitboard expect = 0xFF;
		expect = ~expect;
		REQUIRE(Bitboards::clearRank(RANK_1) == expect);
		
		INFO("Rank 8");
		expect = 0xFF00000000000000;
		expect = ~expect;
		REQUIRE(Bitboards::clearRank(RANK_8) == expect);
	}
	
	SECTION("Out of limits") {
		Bitboard expect = 0;
		expect = ~expect;
		REQUIRE(Bitboards::clearRank(NO_RANK) == expect);
	}
}

TEST_CASE("Clear file", "[bitboard]") {
	
	SECTION("Between limit values") {
		
		INFO("File A");
		Bitboard expect = 0x0101010101010101;
		expect = ~expect;
		REQUIRE(Bitboards::clearFile(FILE_A) == expect);
		
		INFO("File H");
		expect = 0x8080808080808080;
		expect = ~expect;
		REQUIRE(Bitboards::clearFile(FILE_H) == expect);
	}
	
	SECTION("Out of limits") {
		Bitboard expect = 0;
		expect = ~expect;
		REQUIRE(Bitboards::clearFile(NO_FILE) == expect);
	}
}

TEST_CASE("Mask square", "[bitboard]") {
	
	SECTION("Between limit values") {
		
		INFO("Square A1");
		Bitboard expect = 0x1;
		REQUIRE(Bitboards::maskSquare(A1) == expect);
		
		INFO("Square H8");
		expect = 0x8000000000000000;
		REQUIRE(Bitboards::maskSquare(H8) == expect);
	}
	
	SECTION("Out of limits") {
		REQUIRE(Bitboards::maskSquare(NO_SQUARE) == 0);
	}
}

TEST_CASE("Clear square", "[bitboard]") {
	
	SECTION("Between limit values") {
		
		INFO("Square A1");
		Bitboard expect = 0x1;
		expect = ~expect;
		REQUIRE(Bitboards::clearSquare(A1) == expect);
		
		INFO("Square H8");
		expect = 0x8000000000000000;
		expect = ~expect;
		REQUIRE(Bitboards::clearSquare(H8) == expect);
	}
	
	SECTION("Out of limits") {
		Bitboard expect = 0;
		expect = ~expect;
		REQUIRE(Bitboards::clearSquare(NO_SQUARE) == expect);
	}
}
/********************************************************/

/******************** Move test cases *******************/

/********************************************************/