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
pawn::pawn(pawn* pPawn)
{
	pBoard = pPawn->getpBoard();
	column = pPawn->getCol();
	row = pPawn->getRow();
	radius = pPawn->getRadius();
	dir = pPawn->getDir();
	pieceColor = pPawn->getColor();
	circle.setRadius(radius);
	circle.setFillColor(pieceColor);
	circle.setPosition(pPawn->getPos());
}
void pawn::drawPawn(sf::RenderWindow* window)
{
	window->draw(circle);
}
int pawn::tryMove(int newColumn, int newRow)
{
	int dRow = newRow - row;
	int dColumn = newColumn - column;
	if (abs(dRow) != abs(dColumn))//moves have to be diagonal
		return 0;
	if (abs(dColumn) >= 1 && ((dir && dRow >= 1) || (!dir && dRow <= -1)))//path is 1 diagonal length
	{
		if (pBoard->tiles[newColumn][newRow].getpPawn() == nullptr && abs(dRow) == 1)//no other pawn on that square
		{
			pBoard->tiles[column][row].setpPawn(nullptr);//removes pawn old position
			if ((newRow == pBoard->tiles.size() - 1 && dir == 1) || (newRow == 0 && dir == 0))// if on appropriot last row copies a king and deletes pawn
			{
				king* pKing = new king(this);
				pBoard->tiles[newColumn][newRow].setpPawn(pKing);
				delete this;
			}
			else
			{
				pBoard->tiles[newColumn][newRow].setpPawn(this);//sets new pawn position
				column = newColumn;
				row = newRow;
			}

			return 1;
		}
		else if (abs(dRow) == 2 && pBoard->tiles[column + dColumn/2][row + dRow/2].getpPawn() != nullptr && pBoard->tiles[column + dColumn/2][row + dRow/2].getpPawn()->circle.getFillColor() != this->circle.getFillColor())
		{//if jumping over (diagonal 2) AND not jumping over nothing AND jumping over not the same color
			delete pBoard->tiles[column + dColumn / 2][row + dRow / 2].getpPawn();//removes jumped pawn
			pBoard->tiles[column + dColumn / 2][row + dRow / 2].setpPawn(nullptr);//sets the tile as empty

			pBoard->tiles[column][row].setpPawn(nullptr);//removes pawn old position
			if ((newRow == pBoard->tiles.size() - 1 && dir == 1) || (newRow == 0 && dir == 0))// if on appropriot last row copies a king and deletes pawn
			{
				king* pKing = new king(this);
				pBoard->tiles[newColumn][newRow].setpPawn(pKing);
				delete this;
			}
			else
			{
				pBoard->tiles[newColumn][newRow].setpPawn(this);//sets new pawn position
				column = newColumn;
				row = newRow;
			}

			return 2;//return 2 for piece jumped
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
board* pawn::getpBoard()
{
	return pBoard;
}
sf::Color king::getColor() const
{
	return getDir() ? sf::Color::Yellow : sf::Color::Magenta;
}
