#include "Board.h";
#include <iostream>
#include <sstream>
#include <string>
#include <map>

Board::Board() {
	grid.resize(SUBBOARDS_NUM, std::vector<char>(SUBBOARD_SIZE * SUBBOARD_SIZE, '_'));
}

void Board::drawWindow(std::string playerName[], int currentPlayer) {
	clearWindow();
	std::cout << "\033[38;5;206m";
	std::cout << "\033[2;7H" << "   ___  ___ ___  / /____ ____ ____ ";
	std::cout << "\033[3;7H" << "  / _ \\/ -_) _ \\/ __/ _ `/ _ `/ _ \\";
	std::cout << "\033[4;7H" << " / .__/\\__/_//_/\\__/\\_,_/\\_, /\\___/";
	std::cout << "\033[5;7H" << "/_/                     /___/      ";
	std::cout << "\033[0m";

	//std::cout << "\033[0;14H" <<  "\033[38;5;206m" << "PENTAGO" << "\033[0m" << std::endl;
	std::cout << "\033[25;2H" << "\033[38;5;206m" << "Player1: " << "\033[0m" << playerName[0] << "; is current? " << ((currentPlayer == 0) ? "\033[38;5;171mtrue" : "false") << "\033[0m";
	std::cout << "\033[26;2H" << "\033[38;5;206m" << "Player2: " << "\033[0m" << playerName[1] << "; is current? " << ((currentPlayer == 1) ? "\033[38;5;171mtrue" : "false") << "\033[0m";

	for (int i = 0; i < SUBBOARDS_NUM; i++) {
		//\033[row;columnH
		std::stringstream ss; 
		auto column = 8 + (i % 2) * 17;
		auto row = 6 + ((i < 2) ? 0 : 1) * 4;

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

void Board::rotateSubboard(int subboard, int direction) {
	if (subboard < 0 || subboard > 3) { std::cout << "\nwrong subboard"; if (std::cin.get() == '\n') return; }
	if (direction != -90 && direction != 90) { std::cout << "\nwrong direction angle"; if (std::cin.get() == '\n') return; }

	std::map<int, int> rotateValues;
	auto gridCopy = grid[subboard];

	// 90: clockwise, -90: anti-clockwise
	rotateValues[0] = (subboard > 0)? 2 : 6;
	rotateValues[2] = (subboard > 0) ? 8 : 0;
	rotateValues[8] = (subboard > 0) ? 6 : 2;
	rotateValues[6] = (subboard > 0) ? 0 : 8;
	rotateValues[1] = (subboard > 0) ? 5 : 3;
	rotateValues[3] = (subboard > 0) ? 1 : 7;
	rotateValues[5] = (subboard > 0) ? 7 : 1;
	rotateValues[7] = (subboard > 0) ? 3 : 5;

	for (int i = 0; i < SUBBOARD_SIZE * SUBBOARD_SIZE; i++) {
		if (i == 4) continue;
		gridCopy[i] = grid[subboard][rotateValues[i]];
	}
	grid[subboard] = gridCopy;
}

void Board::clearWindow() {
	std::cout << "\033[2J";
}

char Board::getPieceFrom(int subboard, int pos) {
	return grid[subboard].at(pos);
}

void Board::addPieceAt(int subboard, int posX, int posY, int player) {
	if (subboard < 0 || subboard > 3) {std::cout << "\nwrong subboard"; if (std::cin.get() == '\n') return; }
	if (posX < 0 || posX > 2) {std::cout << "\wrong position x"; if (std::cin.get() == '\n') return; }
	if (posY < 0 || posY > 2) {std::cout << "\wrong position y"; if (std::cin.get() == '\n') return; }

	auto pos = (3 * posX + posY);

	if (grid[subboard].at(pos) == '_') {
		switch (player) {
		case 0: grid[subboard][pos] = 'o'; break;
		case 1: grid[subboard][pos] = 'x'; break;
		}
		placedElements++;
	}
}

bool Board::ifAllFieldsFull() {
	auto counter = 0;
	auto fieldsNum = SUBBOARDS_NUM * SUBBOARD_SIZE * SUBBOARD_SIZE;

	for (int i = 0; i < SUBBOARDS_NUM; i++) {
		for (int j = 0; j < SUBBOARD_SIZE * SUBBOARD_SIZE; j++) {
			if (grid[i][j] != '_') counter++;
		}
	}

	if (counter == fieldsNum) return true;
	return false;
}

int Board::getSubboardSize() {
	return SUBBOARD_SIZE;
}

int Board::getSubboardsNum() {
	return SUBBOARDS_NUM;
}

std::vector<std::vector<char>> Board::getGrid() {
	return grid;
}