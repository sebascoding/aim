#include <stdexcept>

#include "cboard.h"
#include "cutils.h"

/*************** Constructors **************/

CBoard::CBoard()
{
	this->init();
}

/*************** Public functions **************/

PieceType CBoard::getPieceAtIndex(int idx)
{
	Bitboard piece = this->indexToBitboard(idx);
	PieceType type;
	
	if (piece & this->pieceBB[nWhite]) {
		if (piece & this->pieceBB[nPawn]) return whitePawns;
		if (piece & this->pieceBB[nKnight]) return whiteKnights;
		if (piece & this->pieceBB[nBishop]) return whiteBishops;
		if (piece & this->pieceBB[nRook]) return whiteRooks;
		if (piece & this->pieceBB[nQueen]) return whiteQueen;
		if (piece & this->pieceBB[nKing]) return whiteKing;
	}
	else {
		if (piece & this->pieceBB[nPawn]) return blackPawns;
		if (piece & this->pieceBB[nKnight]) return blackKnights;
		if (piece & this->pieceBB[nBishop]) return blackBishops;
		if (piece & this->pieceBB[nRook]) return blackRooks;
		if (piece & this->pieceBB[nQueen]) return blackQueen;
		if (piece & this->pieceBB[nKing]) return blackKing;
	}
	
	throw std::runtime_error("Piece does not exist");
}

/*************** Private functions **************/

// Flips bitboard as seen from the other side of the board
Bitboard CBoard::flip(Bitboard b)
{
}

void CBoard::init()
{
	this->pieceBB[nPawn] = 0xFF00000000FF00;
	this->pieceBB[nKnight] = 0x4200000000000042;
	this->pieceBB[nBishop] = 0x2400000000000024;
	this->pieceBB[nRook] = 0x8100000000000081;
	this->pieceBB[nQueen] = 0x800000000000008;
	this->pieceBB[nKing] = 0x1000000000000010;
	this->pieceBB[nWhite] = 0xFFFF;
	this->pieceBB[nBlack] = 0xFFFF000000000000;
	
	/*
	printBB(this->pieceBB[nPawn]);
	printBB(this->pieceBB[nKnight]);
	printBB(this->pieceBB[nBishop]);
	printBB(this->pieceBB[nRook]);
	printBB(this->pieceBB[nQueen]);
	printBB(this->pieceBB[nKing]);
	printBB(this->pieceBB[nWhite]);
	printBB(this->pieceBB[nBlack]);
	*/
}

CBoard::enumPiece CBoard::pieceCode(PieceType pt)
{
	switch (pt) {
		case whitePawns:
		case blackPawns:
			return nPawn;
		case whiteKnights:
		case blackKnights:
			return nKnight;
		case whiteBishops:
		case blackBishops:
			return nBishop;
		case whiteRooks:
		case blackRooks:
			return nRook;
		case whiteQueen:
		case blackQueen:
			return nQueen;
		case whiteKing:
		case blackKing:
			return nKing;
		default:
			throw std::runtime_error("Invalid PieceType given");
	}
}

CBoard::enumPiece CBoard::colorCode(PieceType pt)
{
	switch (pt) {
		case whitePawns:
		case whiteKnights:
		case whiteBishops:
		case whiteRooks:
		case whiteQueen:
		case whiteKing:
			return nWhite;
		case blackPawns:
		case blackKnights:
		case blackBishops:
		case blackRooks:
		case blackQueen:
		case blackKing:
			return nBlack;
		default:
			throw std::runtime_error("Invalid PieceType given");
	}
}

Bitboard CBoard::indexToBitboard(int idx)
{
	return  this->lookup.maskFile(idx%8) & this->lookup.maskRank(idx/8);
}