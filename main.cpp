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
		board.addPieceAt(subboard, posX, posY, game.currentPlayer);

		board.drawBoard();

		std::cout << "\nrotate board (board, rotation(90 or -90))" << std::endl;
		std::getline(std::cin, input);
		iss.clear();
		iss.str(input);
		iss >> subboard >> separator >> rotation;
		board.rotateSubboard(subboard, rotation);

		if (game.checkDraw(0, board)) return 0;
		game.changeTurn();
	}

	return 0;
}