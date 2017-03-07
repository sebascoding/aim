#ifndef BITBOARD_H
#define BITBOARD_H

#include "types.h"

namespace Bitboards
{

	void init();

	const Bitboard maskRank(Rank);
	const Bitboard maskFile(File);
	const Bitboard clearRank(Rank);
	const Bitboard clearFile(File);
	const Bitboard maskSquare(Square);
	const Bitboard clearSquare(Square);
	
	inline const Bitboard emptyBB() {
		Bitboard b = 0;
		return b;
	}
	
	inline const Bitboard fullBB() {
		Bitboard b = 0;
		return ~b;
	}
	
	Square MSB(Bitboard);
	Square LSB(Bitboard);

}

#endif