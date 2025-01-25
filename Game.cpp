#include "Game.h"
#include "Board.h"
#include <iostream>

bool Game::checkDraw(int player, Board board) {
	bool isGameOver = false;
	bool ifBoardFull = board.ifAllFieldsFull();

	if (ifBoardFull) {
		std::cout << "\ngame over, nobody wins" << std::endl;
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
				if (grid[i][j] != '_' 
					&& grid[i][j] == grid[i][j + 1] 
					== grid[i][j + 2] == grid[i + 1][j] 
					== grid[i + 1][j + 1]) {
					isGameOver = true;
				}

				// right subboard is full H
				if (grid[i][j+1] != '_'
					&& grid[i][j + 1] == grid[i][j + 2]
					== grid[i + 1][j] == grid[i + 1][j + 1]
					== grid[i + 1][j + 2]) {
					isGameOver = true;
				}
			}
		}

		// vertical check
		for (int i = 0; i < subboardNum-2; i ++) {
			for (int j = 0; j < subboardSize ; j ++) {

				// up subboard is full V
				if (grid[i][j] != '_'
					&& grid[i][j] == grid[i][j + 3]
					== grid[i][j + 6] == grid[i + 2][j]
					== grid[i + 2][j + 3]) {
					isGameOver = true;
				}

				// down subboard is full V
				if (grid[i][j + 3] != '_'
					&& grid[i][j + 3] == grid[i][j + 6]
					== grid[i + 2][j] == grid[i + 2][j + 3]
					== grid[i + 2][j + 6]) {
					isGameOver = true;
				}
			}
		}

	}



	if (isGameOver) {
		std::cout << "press enter to leave game" << std::endl;
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