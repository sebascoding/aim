// Unit tests for the engine

#include "catch.hpp"

#include "types.h"
#include "position.h"
#include "bitboard.h"
#include "move.h"
#include "uci.h"

#include <iostream>

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
		REQUIRE(p.getPieceAt(sq) == NO_PIECE);
	}
}

TEST_CASE("Position set with FEN string", "[position]") {
	Position p;
	
	SECTION("Pieces position in the board with starting FEN") {
		p.set(UCI::startingFEN);
		
		Bitboard all = 0xFFFF00000000FFFF;
		Bitboard pawn = 0xFF00000000FF00;
		Bitboard knight = 0x4200000000000042;
		Bitboard bishop = 0x2400000000000024;
		Bitboard rook = 0x8100000000000081;
		Bitboard queen = 0x0800000000000008;
		Bitboard king = 0x1000000000000010;
		
		REQUIRE(p.getAllPieces() == all);
		REQUIRE(p.getPieceSet(PAWN) == pawn);
		REQUIRE(p.getPieceSet(KNIGHT) == knight);
		REQUIRE(p.getPieceSet(BISHOP) == bishop);
		REQUIRE(p.getPieceSet(ROOK) == rook);
		REQUIRE(p.getPieceSet(QUEEN) == queen);
		REQUIRE(p.getPieceSet(KING) == king);
		
		for (Square sq = A1; sq <= H8; sq++) {
			CAPTURE(sq);
			if (sq == A1 || sq == H1) {
				
				std::cout << sq << std::endl;
				REQUIRE(p.getPieceAt(sq) == W_ROOK);
			}
			/*
			else if (sq == B1 || sq == G1) {
				REQUIRE(p.getPieceAt(sq) == W_BISHOP);
			}
			else if (sq == C1 || sq == F1) {
				REQUIRE(p.getPieceAt(sq) == W_KNIGHT);
			}
			else if (sq == D1) {
				REQUIRE(p.getPieceAt(sq) == W_QUEEN);
			}
			else if (sq == E1) {
				REQUIRE(p.getPieceAt(sq) == W_KING);
			}
			else if (sq >= A2 && sq <= H2) {
				REQUIRE(p.getPieceAt(sq) == W_PAWN);
			}
			if (sq == A8 || sq == H8) {
				REQUIRE(p.getPieceAt(sq) == B_ROOK);
			}
			else if (sq == B8 || sq == G8) {
				REQUIRE(p.getPieceAt(sq) == B_BISHOP);
			}
			else if (sq == C8 || sq == F8) {
				REQUIRE(p.getPieceAt(sq) == B_KNIGHT);
			}
			else if (sq == D8) {
				REQUIRE(p.getPieceAt(sq) == B_QUEEN);
			}
			else if (sq == E8) {
				REQUIRE(p.getPieceAt(sq) == B_KING);
			}
			else if (sq >= A7 && sq <= H7) {
				REQUIRE(p.getPieceAt(sq) == B_PAWN);
			}
			else {
				CAPTURE(sq);
				REQUIRE(p.getPieceAt(sq) == NO_PIECE);
			}*/
			
		}
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