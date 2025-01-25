#include "Board.h"
#include "Game.h"
#include <iostream>
#include <sstream>
#include <string>

int main() {
	Board board;
	Game game;
	std::string input;
	char separator = ',';
	int subboard, posX, posY, rotation = 0;

	while (true) {
		board.drawBoard();

		std::cout << "\nchoose position (board, row, column) :" << std::endl;
		std::getline(std::cin,input);
		std::istringstream iss(input);
		iss >> subboard >> separator >> posX >> separator >> posY;
		board.addPieceAt(subboard, (3*posX+posY), 0);

		board.drawBoard();

		std::cout << "\nrotate board (board, rotation(90 or -90))" << std::endl;
		std::getline(std::cin, input);
		iss >> subboard >> separator >> rotation;
		board.rotateSubboard(subboard, rotation);

		if (game.checkDraw(0, board)) {
			std::cout << "press enter to leave game" << std::endl;

			while (true) {
				if (std::cin.get() == '\n') return 0;
			}
			
		}
	}

	return 0;
}