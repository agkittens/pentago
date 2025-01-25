#include "Game.h"
#include "Board.h"
#include <iostream>

bool Game::checkDraw(int player, Board board) {
	bool ifBoardFull = board.ifAllFieldsFull();

	if (ifBoardFull) {
		std::cout << "\ngame over, nobody wins" << std::endl;
		return true;
	}

	// logic for checking 5 fields

	return false;
}