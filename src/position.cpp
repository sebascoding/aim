#include <sstream>
#include <algorithm>
#include <iostream>
#include <cstring>	// for memset

#include "position.h"
#include "utils.h"

Position::Position() {
	this->reset();
}

/*

Sets the position in the given FEN. The FEN notation is as follows, being each
field separated by an ASCII space character:

1: Piece placement data

The first field represents the placement of the pieces on the board.  The board
contents are specified starting with the eighth rank and ending with the first
rank.  For each rank, the squares are specified from file a to file h.  White
pieces are identified by uppercase SAN piece letters ("PNBRQK") and black
pieces are identified by lowercase SAN piece letters ("pnbrqk").  Empty squares
are represented by the digits one through eight; the digit used represents the
count of contiguous empty squares along a rank.  A solidus character "/" is
used to separate data of adjacent ranks.


2: Active color

The second field represents the active color.  A lower case "w" is used if
White is to move; a lower case "b" is used if Black is the active player.


3: Castling availability

The third field represents castling availability.  This indicates potential
future castling that may of may not be possible at the moment due to blocking
pieces or enemy attacks.  If there is no castling availability for either side,
the single character symbol "-" is used.  Otherwise, a combination of from one
to four characters are present.  If White has kingside castling availability,
the uppercase letter "K" appears.  If White has queenside castling
availability, the uppercase letter "Q" appears.  If Black has kingside castling
availability, the lowercase letter "k" appears.  If Black has queenside
castling availability, then the lowercase letter "q" appears.  Those letters
which appear will be ordered first uppercase before lowercase and second
kingside before queenside.  There is no white space between the letters.


4: En passant target square

The fourth field is the en passant target square.  If there is no en passant
target square then the single character symbol "-" appears.  If there is an en
passant target square then is represented by a lowercase file character
immediately followed by a rank digit.  Obviously, the rank digit will be "3"
following a white pawn double advance (Black is the active color) or else be
the digit "6" after a black pawn double advance (White being the active color).

An en passant target square is given if and only if the last move was a pawn
advance of two squares.  Therefore, an en passant target square field may have
a square name even if there is no pawn of the opposing side that may
immediately execute the en passant capture.


5: Halfmove clock

The fifth field is a nonnegative integer representing the halfmove clock.  This
number is the count of halfmoves (or ply) since the last pawn advance or
capturing move.  This value is used for the fifty move draw rule.


6: Fullmove number

The sixth and last field is a positive integer that gives the fullmove number.
This will have the value "1" for the first move of a game for both White and
Black.  It is incremented by one immediately after each move by Black.

*/

void Position::set(const std::string& fen) {

	this->reset();
	
	char token;			
	Square sq = A8;
	Bitboard sqBB;
	Piece p;
	PieceType pt;
	Color pc;
			
	std::istringstream iss(fen);
	iss >> std::noskipws;													
	
	// 1 - Piece placement data
	while ((iss >> token) && !isspace(token)) 
	{
		if (isdigit(token))
			sq += Square(token - '0');
		else if (token =='/')
			sq -= Square(FILE_NUM*2);
		else 
		{
			sqBB = Bitboards::maskSquare(sq);		
			p = Utils::charToPiece(token);
			pt = pieceType(p);
			pc = pieceColor(p);
			
			if (p != NO_PIECE && pt != NO_PIECE_TYPE && pc != NO_COLOR)
			{
				this->byTypeBB[pt] |= sqBB;
				this->byColorBB[pc] |= sqBB;
				this->pieces[sq] = p;
			}
			
			sq++;
		}
				
	} 		
}

void Position::print() {
	int sqidx = 0;
	char sq = ' ';
	Piece piece;

	std::cout << " -------------------------------" << std::endl;

	for (int rank = 8 - 1; rank >= 0; rank--) {
		for (int file = 0; file < 8; file++) {

			sqidx = file + rank*8;		
			piece = this->pieces[sqidx];
//			std::cout << piece << std::endl;
			
				switch(piece) {
					case W_PAWN:
						sq = 'P';
						break;
					case B_PAWN:
						sq = 'p';
						break;
					case W_KNIGHT:
						sq = 'N';
						break;
					case B_KNIGHT:
						sq = 'n';
						break;
					case W_BISHOP:
						sq = 'B';
						break;
					case B_BISHOP:
						sq = 'b';
						break;
					case W_ROOK:
						sq = 'R';
						break;
					case B_ROOK:
						sq = 'r';
						break;
					case W_QUEEN:
						sq = 'Q';
						break;
					case B_QUEEN:
						sq = 'q';
						break;
					case W_KING:
						sq = 'K';
						break;
					case B_KING:
						sq = 'k';
						break;
					default:
						sq = ' ';
						break;
				}
				
			std::cout << "| " << sq << " ";
		}
		
		std::cout << "|" << std::endl;
		std::cout << " -------------------------------" << std::endl;
	}
	std::cout << std::endl;
}

void Position::reset() {
	//std::fill(this->byTypeBB, this->byTypeBB + sizeof(this->byTypeBB), 0);
	//std::fill(this->byColorBB, this->byColorBB + sizeof(this->byColorBB), 0);
	//std::fill(this->pieces, this->pieces + sizeof(pieces), NO_PIECE);
	
	std::memset(this->byTypeBB, 0, sizeof(this->byTypeBB));
	std::memset(this->byColorBB, 0, sizeof(this->byColorBB));
	std::memset(this->pieces, NO_PIECE, sizeof(this->pieces));	
}