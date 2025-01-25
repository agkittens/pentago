#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
	Board();
	void addPieceAt(int subboard, int pos, int player);
	void rotateSubboard(int subboardNum, int direction);
	void drawBoard();

	char getPieceFrom(int subboard, int pos);

private:
	std::vector<std::vector<char>> grid;
	const int BOARD_SIZE = 6;
	const int SUBBOARD_SIZE = 3;
	const int SUBBOARDS_NUM = 4;
};

#endif