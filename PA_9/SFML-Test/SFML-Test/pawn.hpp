#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class board;
class tile;

class pawn
{
public:
	pawn(float size, int newColumn, int newRow, bool newDir,sf::Color color, board* newBoard);

	void drawPawn(sf::RenderWindow* window);
	bool tryMove(int newColumn, int newRow);

	sf::Vector2f getPos();
	void setPos(sf::Vector2f newPos);

	float getRadius();
	void setRadius(float newRadius);
	
private:
	sf::CircleShape circle;
	board* pBoard;
	int row;
	int column;
	float radius;
	bool dir; //1 positive direction, 0 negative direction
};

class king : public pawn
{
public:
	
};