#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include "types.h"

class LookupTable
{
	Bitboard _mask_file[8];
	Bitboard _mask_rank[8];
	Bitboard _clear_file[8];
	Bitboard _clear_rank[8];
	
	public:
		LookupTable();
	
		Bitboard maskFile(int file) { return _mask_file[file]; }
		Bitboard maskRank(int rank) { return _mask_rank[rank]; }
		Bitboard clearFile(int file) { return _clear_file[file]; }
		Bitboard clearRank(int rank) { return _clear_rank[rank]; }
	private:
		void init();
};

#endif