#include <SFML/Graphics.hpp>

class tile
{
public:
	tile(int size, int x, int y, sf::Color color);
	
	void drawTile(sf::RenderWindow* window);

	sf::Vector2f getTilePos();
	//no setter for position since tiles should be static
	void setpPawn(void* newpPawn);
	void* getpPawn();

	sf::RectangleShape* getRect();

private:
	sf::RectangleShape rectangle;
	void* pPawn;
};