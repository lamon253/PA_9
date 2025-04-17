#include "tile.hpp"

tile::tile(int size, int x, int y, sf::Color color)
{
	rectangle.setSize(sf::Vector2f{(float)size,(float)size});
	rectangle.setFillColor(color);
	rectangle.setPosition(sf::Vector2f{ (float)x,(float)y});
}
void tile::drawTile(sf::RenderWindow* window)
{
	window->draw(rectangle);
}
sf::Vector2f tile::getTilePos()
{
	return rectangle.getPosition();
}
void tile::setpPawn(void* newpPawn)
{
	pPawn = newpPawn;
}
void* tile::getpPawn()
{
	return pPawn;
}
sf::RectangleShape* tile::getRect()
{
	return &rectangle;
}