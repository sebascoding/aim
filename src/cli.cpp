// Command Line Interface
// White pieces are uppercase: PNBRQK (Pawn, kNight, Bishop, Rook, Queen, King)
// Black pieces are lowercase: pnbrqk
#include "cli.h"

#include "utils.h"

void CLI::update(Color ct)
{/*
	int sqidx = 0;
	char sq = ' ';
	Bitboard piece, base = 1;
	Bitboard allPieces = this->_board->getAllPieces();
	
	std::cout << ((ct == WHITE) ? "White" : "Black") << " moves:" << std::endl; //need to calculate the move

	for (int rank = 8 - 1; rank >= 0; rank--) {
		for (int file = 0; file < 8; file++) {

			sqidx = file + rank*8;		
			piece = base << sqidx;
			
			if (piece & allPieces) {
				switch(this->_board->getPieceAtIndex(sqidx)) {
					case whitePawns:
						sq = 'P';
						break;
					case blackPawns:
						sq = 'p';
						break;
					case whiteKnights:
						sq = 'K';
						break;
					case blackKnights:
						sq = 'n';
						break;
					case whiteBishops:
						sq = 'B';
						break;
					case blackBishops:
						sq = 'b';
						break;
					case whiteRooks:
						sq = 'R';
						break;
					case blackRooks:
						sq = 'r';
						break;
					case whiteQueen:
						sq = 'Q';
						break;
					case blackQueen:
						sq = 'q';
						break;
					case whiteKing:
						sq = 'K';
						break;
					case blackKing:
						sq = 'k';
						break;
				}
			}
			else
				sq = ' ';
				
			std::cout << sq;
		}
		
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/
}