#include <SFML/Graphics.hpp>

class tile
{
public:
	tile(int size, int x, int y, sf::Color color);
	
	void drawTile(sf::RenderWindow* window);

	sf::CircleShape* getpCircle();
	void setpCircle(sf::CircleShape* newpCircle);

private:
	sf::CircleShape* pCircle;
	sf::RectangleShape rectangle;
};