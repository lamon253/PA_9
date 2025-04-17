#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class pawn;
class board;

class tile
{
public:
	tile(int size, int x, int y, sf::Color color);
	
	void drawTile(sf::RenderWindow* window);

	sf::Vector2f getTilePos();
	//no setter for position since tiles should be static
	void setpPawn(pawn* newpPawn);
	pawn* getpPawn();

	sf::RectangleShape* getRect();

private:
	sf::RectangleShape rectangle;
	pawn* pPawn;
};