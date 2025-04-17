#include "tile.hpp"

tile::tile(int size, int x, int y, sf::Color color)
{
	rectangle.setSize(sf::Vector2f{(float)size,(float)size});
	rectangle.setFillColor(color);
	rectangle.setPosition(sf::Vector2f{ (float)x,(float)y});

	pCircle = nullptr;
}
void tile::drawTile(sf::RenderWindow* window)
{
	window->draw(rectangle);
	if (pCircle != nullptr)
		window->draw(*pCircle);
}
sf::CircleShape* tile::getpCircle()
{
	return pCircle;
}
void tile::setpCircle(sf::CircleShape* newpCircle)
{
	pCircle = newpCircle;
}