#include "pawn.hpp"
#include "board.hpp"

pawn::pawn(float size, int newColumn, int newRow, bool newDir, sf::Color color, board* newBoard)
{
	pBoard = newBoard;

	float len = size * newBoard->tiles[column][radius].getRect()->getSize().x;
	radius = size*len/2;

	column = newColumn;
	row = newRow;

	pieceColor = color;

	dir = newDir;
	circle.setRadius(radius);
	circle.setPosition(pBoard->tiles[column][row].getTilePos() + sf::Vector2f{ len/2 - radius, len / 2 - radius });
	circle.setFillColor(getColor());

	pBoard->tiles[column][row].setpPawn(this);
	//having a pointer to any pawn on a tile in its class will be helpful when checking if a tile is empty
	//and deleting pawns when they are eliminated
}
void pawn::drawPawn(sf::RenderWindow* window)
{
	window->draw(circle);
}
bool pawn::tryMove(int newColumn, int newRow)
{
	int dRow = newRow - row;
	int dColumn = newColumn - column;
	if (abs(dRow) != abs(dColumn))//moves have to be diagonal
		return false;
	if (abs(dColumn) >= 1 && ((dir && dRow >= 1) || (!dir && dRow <= -1)))//path is 1 diagonal length
	{
		if (pBoard->tiles[newColumn][newRow].getpPawn() == nullptr && abs(dRow) == 1)//no other pawn on that square
		{
			pBoard->tiles[newColumn][newRow].setpPawn(this);
			pBoard->tiles[column][row].setpPawn(nullptr);
			column = newColumn;
			row = newRow;
			return true;
		}
		else if (abs(dRow) == 2 && pBoard->tiles[column + dColumn/2][row + dRow/2].getpPawn() != nullptr && pBoard->tiles[column + dColumn/2][row + dRow/2].getpPawn()->circle.getFillColor() != this->circle.getFillColor())
		{//if jumping over (diagonal 2) AND not jumping over nothing AND jumping over not the same color
			delete pBoard->tiles[column + dColumn / 2][row + dRow / 2].getpPawn();//removes jumped pawn
			pBoard->tiles[column + dColumn / 2][row + dRow / 2].setpPawn(nullptr);//sets the tile as empty
			pBoard->tiles[newColumn][newRow].setpPawn(this);//sets new pawn position
			pBoard->tiles[column][row].setpPawn(nullptr);//removes pawn old position
			column = newColumn;
			row = newRow;
			return true;
		}
	}
	return false;
}
sf::Vector2f pawn::getPos()
{
	return { (float)column, (float)row};
}
void pawn::setPos(sf::Vector2f newPos)
{
	circle.setPosition(newPos);
}
float pawn::getRadius()
{
	return radius;
}
void pawn::setRadius(float newRadius)
{
	radius = newRadius;
}

sf::Color king::getColor() const
{
	return getDir() ? sf::Color::Yellow : sf::Color::Magenta;
}
