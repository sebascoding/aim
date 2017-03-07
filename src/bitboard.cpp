#include "bitboard.h"

Bitboard rankBB[RANK_NUM];
Bitboard fileBB[FILE_NUM];
Bitboard squareBB[SQUARE_NUM];
	
namespace Bitboards {
	
	void init() {
		
		for (Rank r = RANK_1; r <= RANK_8; r++) {
			rankBB[r] = ((Bitboard)0xFF) << 8*r;
		}
		
		for (File f = FILE_A; f <= FILE_H; f++) {
			fileBB[f] = ((Bitboard)0x0101010101010101) << f;
		}
		
		for (Square sq = A1; sq <= H8; sq++) {
			squareBB[sq] = ((Bitboard)1) << sq;
		}
	}

	const Bitboard maskRank(Rank r) {
		return r >= RANK_1 && r <= RANK_8 ? rankBB[r] : emptyBB();
	}
	
	const Bitboard maskFile(File f) {
		return f >= FILE_A && f <= FILE_H ? fileBB[f] : emptyBB();
	}
	
	const Bitboard clearRank(Rank r) {
		return r >= RANK_1 && r <= RANK_8 ? ~rankBB[r] : fullBB();
	}
	
	const Bitboard clearFile(File f) {
		return f >= FILE_A && f <= FILE_H ? ~fileBB[f] : fullBB();
	}
			
	const Bitboard maskSquare(Square sq) {
		return sq >= A1 && sq <= H8 ? squareBB[sq] : emptyBB();
	}
	
	const Bitboard clearSquare(Square sq) {
		return sq >= A1 && sq <= H8 ? ~squareBB[sq] : fullBB();
	}
}