#ifndef UTILS_H
#define UTILS_H

#include "types.h"

namespace Utils {
	Piece charToPiece(char p);
	char pieceToChar(Piece p);

	void printBB(Bitboard b);
}

#endif