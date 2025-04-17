#include "tile.hpp"
#include "pawn.hpp"

tile::tile(int size, int x, int y, sf::Color color)
{
	rectangle.setSize(sf::Vector2f{(float)size,(float)size});
	rectangle.setFillColor(color);
	rectangle.setPosition(sf::Vector2f{ (float)x,(float)y});

	pPawn = nullptr;
}
void tile::drawTile(sf::RenderWindow* window)
{
	window->draw(rectangle);
	if (pPawn != nullptr)
		pPawn->drawPawn(window);
}
sf::Vector2f tile::getTilePos()
{
	return rectangle.getPosition();
}
void tile::setpPawn(pawn* newpPawn)
{
	pPawn = newpPawn;
	if (pPawn != nullptr)
	{
		pPawn->setPos(rectangle.getPosition() + sf::Vector2f{rectangle.getSize().x / 2 - pPawn->getRadius(), rectangle.getSize().x / 2 - pPawn->getRadius()});
	}
}
pawn* tile::getpPawn()
{
	return pPawn;
}
sf::RectangleShape* tile::getRect()
{
	return &rectangle;
}