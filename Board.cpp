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
		auto column = 2 + (i % 2) * 15;
		auto row = 2 + ((i < 2) ? 0 : 1) * 4;

		ss << "\033[" << row << ";" << column << "H";
		auto terminalPosition = ss.str();
		std::cout << terminalPosition;

		for (int field = 0; field < SUBBOARD_SIZE * SUBBOARD_SIZE; field++) {

			switch (field % 3) {
			case 0: std::cout << "\n| " << getPieceFrom(i, field) << " |";
			case 1 && 2: std::cout << "| " << getPieceFrom(i, field) << " |";
			}
		}
	}
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
