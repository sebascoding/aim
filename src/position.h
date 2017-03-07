#ifndef POSITION_H
#define POSITION_H

#include <string>

#include "types.h"
#include "bitboard.h"

class Position {
	
	Bitboard byTypeBB[PIECE_TYPE_NUM];
	Bitboard byColorBB[COLOR_NUM];
	Piece pieces[SQUARE_NUM]; // more mem but easier to find what piece is in given sq

	public:
		Position();

		void set(const std::string& fen);
		
		void print(); // for debugging purposes
		
//		PieceType getPieceAtIndex(int idx);
		
		Bitboard getAllPieces() { return byColorBB[WHITE] | byColorBB[BLACK]; }
		Bitboard getColorSet(Color c) { return byColorBB[WHITE]; } // TODO: boundaries
		Bitboard getPieceSet(PieceType pt) { return byTypeBB[pt]; } // TODO: boundaries
		Bitboard getPieceSet(Piece p) { return byColorBB[p/6] & byTypeBB[p%6]; } // TODO: boundaries
		Piece getPieceAt(Square sq) { return pieces[sq]; } // TODO: boundaries

//		Bitboard getPieceSet(PieceType pt) { return pieceBB[pieceCode(pt)] & pieceBB[colorCode(pt)]; }
//		Bitboard getWhitePawns() { return pieceBB[nPawn] & pieceBB[nWhite]; }
//		Bitboard getPawns(ColorType ct) { return pieceBB[nPawn] & pieceBB[ct]; }
	private:
		void reset();
//   	enumPiece pieceCode(PieceType);
//   	enumPiece colorCode(PieceType);
//   	Bitboard flip(Bitboard b);
//   	void init();
//   	Bitboard indexToBitboard(int idx);	
};

#endif