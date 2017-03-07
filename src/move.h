#ifndef MOVE_H
#define MOV_H

#include "types.h"

/* Moves are encoded in a 16 bit integer.

	Bits 0-5:   Encode origin square
	Bits 6-11:  Encode destination square
	Bits 12-15: Flags for special moves such as castling, capture, ep, etc.
	
	Flags structure:
	
		Bits 0-1: Special bits (castling, ep, etc)
		Bit 2:    Capture
		Bit 3:    Promotion
		
	For more insight in flags codes see MoveFlags in types.h.
	
*/
class Move {

	unsigned int move;
	
	enum MoveFlag : unsigned int {
		SPECIAL_FLAG = 0x3 << 12,
		CAPTURE_FLAG = 0x4 << 12,
		PROMOTION_FLAG = 0x8 << 12
	};
			
	public:
		Move(Square from, Square to, unsigned int flags) {
			move = ((flags & 0xf) << 12) | ((to & 0x3f) << 6) | (from & 0x3f);
		}
		
		Square getFrom() { return Square(move & 0x3f); }
		Square getTo() { return Square(move & (0x3f << 6)); }
		unsigned int getFlags() { return move & (0xf << 12); }
		
		void setFrom(Square from) { move &= ~0x3f; move |= from & 0x3f; }
		void setTo(Square to) { move &= ~(0x3f << 6); move |= to & (0x3f << 6); }
		void setFlags(unsigned int flags) { move &= ~(0xf << 12); move |= flags & (0xf << 12); }
		
		bool isCapture() { return (move & CAPTURE_FLAG) != 0;}
		bool isPromotion() { return (move & PROMOTION_FLAG) != 0;}
};

#endif