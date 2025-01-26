#include "Game.h"
#include "Board.h"
#include <iostream>

bool Game::checkDraw(int player, Board board) {
	bool isGameOver = false;
	bool ifBoardFull = board.ifAllFieldsFull();

	if (ifBoardFull) {
		std::cout << "\033[38;5;171m" << "\ngame over, nobody wins" << "\033[0m";
		isGameOver = true;
	}

	// logic for checking 5 fields
	if (board.placedElements > 8) {
		auto subboardNum = board.getSubboardsNum();
		auto subboardSize = board.getSubboardSize();
		auto grid = board.getGrid();

		// horizontal check
		for (int i = 0; i < subboardNum; i += 2) {
			for (int j = 0; j < subboardSize * subboardSize; j+=3) {
				// left subboard is full H
				char conditionL[5] = { grid[i][j], grid[i][j + 1], grid[i][j + 2], grid[i + 1][j], grid[i + 1][j + 1] };
				if (checkCondition(conditionL)) isGameOver = true;

				// right subboard is full H
				char conditionR[5] = { grid[i][j+1], grid[i][j + 2], grid[i+1][j], grid[i + 1][j+1], grid[i + 1][j + 2] };
				if (checkCondition(conditionR)) isGameOver = true;
			}
		}

		// vertical check
		for (int i = 0; i < subboardNum-2; i ++) {
			for (int j = 0; j < subboardSize ; j ++) {
				// up subboard is full V
				char conditionU[5] = { grid[i][j], grid[i][j + 3], grid[i][j + 6], grid[i + 2][j], grid[i + 2][j + 3] };
				if (checkCondition(conditionU)) isGameOver = true;

				// down subboard is full V
				char conditionD[5] = { grid[i][j+3], grid[i][j + 6], grid[i + 2][j], grid[i + 2][j + 3], grid[i + 2][j + 6] };
				if (checkCondition(conditionD)) isGameOver = true;
			}
		}

		// diagonal check left-right
		char conditionDiag1[5] = { grid[0][0], grid[0][4], grid[0][8], grid[3][0], grid[3][4] };
		if (checkCondition(conditionDiag1)) isGameOver = true;

		char conditionDiag2[5] = { grid[0][4], grid[0][8], grid[3][0], grid[3][4], grid[3][8] };
		if (checkCondition(conditionDiag2)) isGameOver = true;

		char conditionDiag3[5] = { grid[0][1], grid[0][5], grid[1][6], grid[3][1], grid[3][5] };
		if (checkCondition(conditionDiag3)) isGameOver = true;

		// diagonal check right-to-left
		char conditionDiag4[5] = { grid[1][2], grid[1][4], grid[1][6], grid[2][2], grid[2][4] };
		if (checkCondition(conditionDiag4)) isGameOver = true;

		char conditionDiag5[5] = { grid[1][4], grid[1][6], grid[2][2], grid[2][4], grid[2][6] };
		if (checkCondition(conditionDiag5)) isGameOver = true;

		char conditionDiag6[5] = { grid[1][1], grid[1][3], grid[0][8], grid[2][1], grid[2][3] };
		if (checkCondition(conditionDiag6)) isGameOver = true;			
	}

	if (isGameOver) {
		std::cout << "\npress enter to leave game" << std::endl;
		while (true) {
			if (std::cin.get() == '\n') return true;
		}
	}

	return false;
}

void Game::changeTurn() {
	if (currentPlayer == 0) currentPlayer = 1;
	else if (currentPlayer == 1) currentPlayer = 0;
}

bool Game::checkCondition(char fields[5]) {
	if (fields[0] != ' '
		&& fields[0] == fields[1]
		&& fields[0] == fields[2]
		&& fields[0] == fields[3]
		&& fields[0] == fields[4]) {
		std::cout << "\033[38;5;171m" << "\player: " << playerName[currentPlayer] << " wins" << "\033[0m";
		return true;
	}
	return false;
}