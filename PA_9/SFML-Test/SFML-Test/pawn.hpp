#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class board;
class tile;

class pawn
{
public:
	pawn(float size, int column, int row, sf::Color color, board* newBoard);

	void drawPawn(sf::RenderWindow* window);
	bool tryMove(int column, int row);
	
private:
	sf::CircleShape circle;
	board* pBoard;
	int row;
	int column;
};

class king : public pawn
{
public:
	
};