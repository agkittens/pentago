#include "Board.h"
#include "Game.h"
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>

int main() {
	Board board;
	Game game;
	std::string input;
	char separator = ',';
	int subboard, posX, posY, rotation = 0;

	std::cout << "\033[38;5;206m";
	std::cout << "\033[5;7H" << "   ___  ___ ___  / /____ ____ ____ ";
	std::cout << "\033[6;7H" << "  / _ \\/ -_) _ \\/ __/ _ `/ _ `/ _ \\";
	std::cout << "\033[7;7H" << " / .__/\\__/_//_/\\__/\\_,_/\\_, /\\___/";
	std::cout << "\033[8;7H" << "/_/                     /___/      ";
	std::cout<< "\033[0m";

	std::cout << "\033[11;14H" << "enter player1 name: ";
	std::getline(std::cin, game.playerName[0]);
	std::cout << "\033[12;14H" << "enter player2 name: ";
	std::getline(std::cin, game.playerName[1]);
	std::this_thread::sleep_for(std::chrono::seconds(2));

	while (true) {
		board.drawWindow(game.playerName, game.currentPlayer);

		std::cout << "\nchoose position (board, row, column) :" << std::endl;
		std::getline(std::cin,input);
		std::istringstream iss(input);
		iss >> subboard >> separator >> posX >> separator >> posY;
		board.addPieceAt(subboard, posX, posY, game.currentPlayer);

		board.drawWindow(game.playerName, game.currentPlayer);

		std::cout << "\nrotate board (board, rotation(90 or -90))" << std::endl;
		std::getline(std::cin, input);
		iss.clear();
		iss.str(input);
		iss >> subboard >> separator >> rotation;
		board.rotateSubboard(subboard, rotation);

		if (game.checkDraw(0, board)) return 0;
		game.changeTurn();
	}

	return 0;
}