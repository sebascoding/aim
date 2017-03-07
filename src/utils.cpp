#include "utils.h"

#include <iostream>

namespace Utils {
	// According to SEN notation
	Piece charToPiece(char p) {
		switch(p)
		{
			case 'P':
				return W_PAWN;
			case 'N':
				return W_KNIGHT;
			case 'B':
				return W_BISHOP;
			case 'R':
				return W_ROOK;
			case 'Q':
				return W_QUEEN;
			case 'K':
				return W_KING;
			case 'p':
				return B_PAWN;
			case 'n':
				return B_KNIGHT;
			case 'b':
				return B_BISHOP;
			case 'r':
				return B_ROOK;
			case 'q':
				return B_QUEEN;
			case 'k':
				return B_KING;
			default:
				return NO_PIECE;
		}
	}
	
	void printBB(Bitboard b)
	{
		int sq = 0;
		Bitboard base = 1;
		
		for (int rank = 8 - 1; rank >= 0; rank--) {
			for (int file = 0; file < 8; file++) {
			
				sq = (base << (file + rank*8)) & b ? 1 : 0;
				
				std::cout << sq << " ";
			}
			
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}