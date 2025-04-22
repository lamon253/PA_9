#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "tile.hpp"

class pawn;

class board
{
public:
	board(int height, int width, int rows, int columns, sf::Color color1, sf::Color color2);

	void drawBoard(sf::RenderWindow* window);

	pawn* pieceSearch(int col, int row, std::vector<pawn*> pieces) const;

private:
	friend class pawn;
	sf::Color color1;
	sf::Color color2;
	std::vector<std::vector<tile>> tiles;
};
