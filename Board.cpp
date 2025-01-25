#include "Board.h";
#include <iostream>
#include <sstream>
#include <string>

Board::Board() {
	grid.resize(SUBBOARDS_NUM, std::vector<char>(SUBBOARD_SIZE * SUBBOARD_SIZE, '_'));
}

void Board::drawBoard() {

	for (int i = 0; i < SUBBOARDS_NUM; i++) {
		//\033[row;columnH
		std::stringstream ss;
		auto column = 2 + (i % 2) * 17;
		auto row = 2 + ((i < 2) ? 0 : 1) * 4;

		for (int field = 0; field < SUBBOARD_SIZE * SUBBOARD_SIZE; field++) {
			if (field % 3 == 0) {
				++row;
				ss << "\033[" << row << ";" << column << "H";
				auto terminalPosition = ss.str();
				std::cout << terminalPosition;
			}
			std::cout << "| " << getPieceFrom(i, field) << " |";
		}
	}
	std::cout << "\n";

}

void Board::clearWindow() {
	std::cout << "\033[2J";
}

char Board::getPieceFrom(int subboard, int pos) {
	return grid[subboard].at(pos);
}

void Board::addPieceAt(int subboard, int pos, int player) {
	if (grid[subboard].at(pos) == '_') {
		switch (player) {
		case 0: grid[subboard][pos] = 'o';
		case 1: grid[subboard][pos] = 'x';
		}
	}
}
