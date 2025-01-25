#include "Board.h"
#include <iostream>
#include <sstream>
#include <string>

int main() {
	Board board;
	std::string input;
	char separator = ',';
	int subboard, posX, posY, rotation = 0;

	while (true) {
		board.drawBoard();

		std::cout << "choose position (board, row, column) :" << std::endl;
		std::getline(std::cin,input);
		std::istringstream iss(input);
		iss >> subboard >> separator >> posX >> separator >> posY;
		board.addPieceAt(subboard, (3*posX+posY), 0);

		board.drawBoard();

		std::cout << "rotate board (board, rotation(90 or -90))" << std::endl;
		std::getline(std::cin, input);
		iss >> subboard >> separator >> rotation;
		board.rotateSubboard(subboard, rotation);
	}

	return 0;
}