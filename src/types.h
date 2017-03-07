#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

typedef uint64_t Bitboard;

enum PieceType {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,
	NO_PIECE_TYPE,
	PIECE_TYPE_NUM = 6
};

enum Color {
	WHITE,
	BLACK,
	NO_COLOR,
	COLOR_NUM = 2
};

enum Piece {
	W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
	B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,
	NO_PIECE,
	PIECE_NUM = 16
};

enum Rank {
	RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8,
	NO_RANK,
	RANK_NUM = 8
};

enum File {
	FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H,
	NO_FILE,
	FILE_NUM = 8
};

enum Square : int {
	A1, B1, C1, D1, E1, F1, G1, H1,
	A2, B2, C2, D2, E2, F2, G2, H2,
	A3, B3, C3, D3, E3, F3, G3, H3,
	A4, B4, C4, D4, E4, F4, G4, H4,
	A5, B5, C5, D5, E5, F5, G5, H5,
	A6, B6, C6, D6, E6, F6, G6, H6,
	A7, B7, C7, D7, E7, F7, G7, H7,
	A8, B8, C8, D8, E8, F8, G8, H8,
	NO_SQUARE,
	SQUARE_NUM = 64
};

// Move codes as specified in move.h
enum MoveCode : unsigned int {
	QUIET_MOVE,
	DOUBLE_PAWN_PUSH,
	KING_CASTLE,
	QUEEN_CASTLE,
	CAPTURE,
	EP_CAPTURE,
	KNIGHT_PROMO,
	BISHOP_PROMO,
	ROOK_PROMO,
	QUEEN_PROMO,
	KNIGHT_PROMO_CAPTURE,
	BISHOP_PROMO_CAPTURE,
	ROOK_PROMO_CAPTURE,
	QUEEN_PROMO_CAPTURE,
};

/*
inline Square operator+(Square a, Square b) { return Square(int(a) + int(b)); }
inline Square operator-(Square a, Square b) { return Square(int(a) - int(b)); }
inline Square& operator+=(Square& a, Square b) { return a = a + b; }
inline Square& operator-=(Square& a, Square b) { return a = a - b; }
inline Square operator++(Square& a, int ) { 
	auto old = a;
	a = Square(int(a) + 1);
	return old;
}
*/

#define ENABLE_BASE_OPERATORS_ON(T)                             \
inline T operator+(T d1, T d2) { return T(int(d1) + int(d2)); } \
inline T operator-(T d1, T d2) { return T(int(d1) - int(d2)); } \
inline T operator-(T d) { return T(-int(d)); }                  \
inline T& operator+=(T& d1, T d2) { return d1 = d1 + d2; }      \
inline T& operator-=(T& d1, T d2) { return d1 = d1 - d2; }      \

#define ENABLE_FULL_OPERATORS_ON(T)                             \
ENABLE_BASE_OPERATORS_ON(T)                                     \
inline T operator*(int i, T d) { return T(i * int(d)); }        \
inline T operator*(T d, int i) { return T(int(d) * i); }        \
inline T& operator++(T& d, int) { return d = T(int(d) + 1); }        \
inline T& operator--(T& d) { return d = T(int(d) - 1); }        \
inline T operator/(T d, int i) { return T(int(d) / i); }        \
inline int operator/(T d1, T d2) { return int(d1) / int(d2); }  \
inline T& operator*=(T& d, int i) { return d = T(int(d) * i); } \
inline T& operator/=(T& d, int i) { return d = T(int(d) / i); }

ENABLE_FULL_OPERATORS_ON(PieceType)
ENABLE_FULL_OPERATORS_ON(Color)
ENABLE_FULL_OPERATORS_ON(Piece)
ENABLE_FULL_OPERATORS_ON(Rank)
ENABLE_FULL_OPERATORS_ON(File)
ENABLE_FULL_OPERATORS_ON(Square)

#undef ENABLE_FULL_OPERATORS_ON
#undef ENABLE_BASE_OPERATORS_ON

inline Color pieceColor(Piece p) { return Color(int(p)/PIECE_TYPE_NUM); }
inline PieceType pieceType(Piece p) {
	return PieceType(int(p) < PIECE_TYPE_NUM*2 ? int(p)%PIECE_TYPE_NUM : NO_PIECE_TYPE );
}

#endif