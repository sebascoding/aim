// Little-endian rank-file mapping

#ifndef CBOARD_H
#define CBOARD_H

#include <string>

#include "types.h"

// Contains state of the board and provide functions for accessing pieces bitboards 
class CBoard
{
	Bitboard byTypeBB[PIEC_TYPE_NUM];
	Bitboard byColor[COLOR_NUM];
	Piece pieces[SQUARE_NUM]; // more mem but easier to find what piece is in given sq

	public:
		CBoard();

		
//		PieceType getPieceAtIndex(int idx);
		
//		Bitboard getAllPieces() { return pieceBB[nWhite] | pieceBB[nBlack]; }
//		Bitboard getPieceSet(PieceType pt) { return pieceBB[pieceCode(pt)] & pieceBB[colorCode(pt)]; }
//		Bitboard getWhitePawns() { return pieceBB[nPawn] & pieceBB[nWhite]; }
//		Bitboard getPawns(ColorType ct) { return pieceBB[nPawn] & pieceBB[ct]; }
	private:
//   	enumPiece pieceCode(PieceType);
//   	enumPiece colorCode(PieceType);
//   	Bitboard flip(Bitboard b);
//   	void init();
//   	Bitboard indexToBitboard(int idx);
};


#endif