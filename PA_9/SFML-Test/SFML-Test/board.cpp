#include "board.hpp"

board::board(int height, int width, int rows, int columns, sf::Color color1, sf::Color color2)
{
	int size = height/rows;
	sf::Color colors[2] = {color1, color2};//color of tile is based on if the sum of the row and column is even or odd
	if (width / columns < size)
		size = width / columns;
	//given the size parameters height and width this detirmines the appopriot size
	// of tiles since a non-square board isnt abnormal but non-square tiles would be 
	for (int i = 0; i < columns; i++)
	{
		tiles.push_back(std::vector<tile> {});
		for (int j = 0; j < rows; j++)
		{
			tiles[i].push_back(tile(size, i*size, j*size, colors[(i + j) % 2]));
		}
	}
}
void board::drawBoard(sf::RenderWindow* window)
{
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles[i].size(); j++)
		{
			tiles[i][j].drawTile(window);
		}
	}
}

pawn* board::pieceSearch(int col, int row, std::vector<pawn*> pieces) const
{
	for (const auto& pawn : pieces)
	{
		if (pawn->getRow() == row && pawn->getCol() == col)
		{
			return pawn;
		}
	}
	return nullptr;
}

tile* board::getTile(int column, int row)
{
	if (column >= 0 && column < this->tiles.size() && row >= 0 && row < this->tiles[column].size())
		return &(this->tiles[column][row]);
	return nullptr;
}