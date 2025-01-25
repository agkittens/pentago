#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
	bool checkDraw(int player, Board board);
};

#endif