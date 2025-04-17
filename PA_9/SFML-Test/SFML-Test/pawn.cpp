#include "pawn.hpp"
#include "board.hpp"

pawn::pawn(float size, int newColumn, int newRow, sf::Color color, board* newBoard)
{
	pBoard = newBoard;

	float radius = newBoard->tiles[0][0].getRect()->getSize().x/2;

	column = newColumn;
	row = newRow;
	circle.setRadius((int)radius*size);
	circle.setPosition(sf::Vector2f{ (float)(column*2+1-size) * radius, (float)(row*2+1-size) * radius });
	circle.setFillColor(color);

	pBoard->tiles[column][row].setpPawn(this);
	//having a pointer to any pawn on a tile in its class will be helpful when checking if a tile is empty
	//and deleting pawns when they are eliminated
}
void pawn::drawPawn(sf::RenderWindow* window)
{
	window->draw(circle);
}
bool pawn::tryMove(int column, int row)
{
	return true;
}
