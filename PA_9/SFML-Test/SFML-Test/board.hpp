#include "tile.hpp"
#include <vector>

class board
{
public:
	board(int height, int width, int rows, int columns, sf::Color color1, sf::Color color2);

	void drawBoard(sf::RenderWindow* window);
private:
	sf::Color color1;
	sf::Color color2;
	std::vector<std::vector<tile>> tiles;
};