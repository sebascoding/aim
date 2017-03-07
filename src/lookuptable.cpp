#include "lookuptable.h"

#include "cutils.h"

LookupTable::LookupTable()
{ 
	this->init();
}

void LookupTable::init()
{
	Bitboard base_maskrank = 0xFF;
	Bitboard base_maskfile = 0x101010101010101; 

	for (int i = 0; i < 8; i++) {
		this->_mask_rank[i] = base_maskrank << 8*i;
		this->_mask_file[i] = base_maskfile << i;
		
		this->_clear_rank[i] = ~(this->_mask_rank[i]);
		this->_clear_file[i] = ~(this->_mask_file[i]);
	}
}