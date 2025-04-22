#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class board;
class tile;

class pawn
{
public:
	pawn(float size, int newColumn, int newRow, bool newDir, sf::Color color, board* newBoard);
	pawn(pawn* pPawn);

	virtual void drawPawn(sf::RenderWindow* window);
	virtual int tryMove(int newColumn, int newRow, std::vector<pawn*> &pieces);
	virtual int checkMove(int newColumn, int newRow);

	sf::Vector2f getPos();
	void setPos(sf::Vector2f newPos);

	virtual bool isKing() const { return false; }

	int getRow() const { return row; }
	int getCol() const { return column; }

	float getRadius();
	void setRadius(float newRadius);

	board* getpBoard();

	virtual sf::Color getColor() const { return pieceColor; }

	bool getDir() const { return dir; }
	
protected:
	sf::CircleShape circle;
	sf::Color pieceColor;
	board* pBoard;
	int row;
	int column;
	float radius;
	bool dir; //1 positive direction, 0 negative direction
};

class king : public pawn
{
public:
	king(const pawn& p);
	
	int tryMove(int newColumn, int newRow, std::vector<pawn*>& pieces) override;
	int checkMove(int newColumn, int newRow) override;
	bool isKing() const override { return true; }

	sf::Color getColor() const override;

};

int checkStuck(pawn* pPawn);