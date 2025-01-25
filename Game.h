#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
	int currentPlayer = 0;
	std::string playerName[2] = { "","" };

	bool checkDraw(int player, Board board);
	void changeTurn();
};

#endif