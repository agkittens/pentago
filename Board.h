#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board {
public:
	Board();

	int placedElements = 0;

	void addPieceAt(int subboard, int posX, int posY, int player);
	void rotateSubboard(int subboard, int direction);
	void drawWindow(std::string playerName[], int currentPlayer);
	bool ifAllFieldsFull();

	char getPieceFrom(int subboard, int pos);
	int getSubboardSize();
	int getSubboardsNum();
	std::vector<std::vector<char>>getGrid();

private:
	std::vector<std::vector<char>> grid;
	const int SUBBOARD_SIZE = 3;
	const int SUBBOARDS_NUM = 4;

	void clearWindow();
};

#endif