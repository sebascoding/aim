#include <cstdlib>

#include <string>
#include <sstream>

#include "cli.h"
#include "utils.h"
#include "types.h"
#include "position.h"
#include "uci.h"

enum Turn
{
	human,
	computer
};


int main()
{
	Color human_color = WHITE;
	Color computer_color = static_cast<Color>(!human_color);
	Turn turn = human_color == WHITE ? human : computer;
	
	Bitboards::init();
	
	//CBoard board;
	//CLI cli(&board);
	
	/*
	while (1) {
		if (turn == human) {
		}
		else {
		}
	}
	*/
	
	//cli.update(white);
	
	/*
	Position pos;
	pos.set(UCI::startingFEN);
	pos.print();
	pos.set("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1");
	pos.print();
	*/
										
	return EXIT_SUCCESS;
}