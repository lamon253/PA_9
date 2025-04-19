/*
* Description: function definitions for test cases
*
* Test.cpp
*/

#include "Test.hpp"

// Test if the SFML window works correctly.
void Test::TestSFMLWindowStatus()
{
    // Create SFML window
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML Window Test");

    // Check the window open status
    if (!window.isOpen())
    {
        std::cerr << "Error: Window failed to open." << std::endl;
        return;
    }

    // Close the window after testing  
    window.close();

    std::cout << "SFML Window Test PASSED." << std::endl;
}


// Test if tile is displayed correctly on the screen.
void Test::TestTileDisplay()
{
    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "Tile Display Test");


    // Testing Parameters
    const int tileSize = 50;
    const sf::Color testColor = sf::Color::Red;
    const int testX = 100;
    const int testY = 100;


    // 1. Test drawTile()
    tile testTile(tileSize, testX, testY, testColor);

    // Check rantangle existence
    sf::RectangleShape* tileRect = testTile.getRect();

    if (tileRect == nullptr)
    {
        window.close();
        throw std::runtime_error("FAILED: getRect() returned nullptr"); // Rectangle failed to be created
    }

    // Check if the position matches
    sf::Vector2f tilePos = testTile.getTilePos();

    if (tilePos.x != testX || tilePos.y != testY)
    {
        window.close();
        throw std::runtime_error("FAILED: Tile position incorrect");
    }

    // Check if the rectangle size matches
    if (tileRect->getSize().x != tileSize || tileRect->getSize().y != tileSize)
    {
        window.close();
        throw std::runtime_error("FAILED: Tile size incorrect");
    }

    // Check color fill-in
    if (tileRect->getFillColor() != testColor)
    {
        window.close();
        throw std::runtime_error("FAILED: Tile color incorrect");
    }

    // Check drawing functionality
    window.clear(sf::Color::White);
    testTile.drawTile(&window);
    window.display();


    // 2. Test Pawn setter and getter
    board b(1000, 1000, 8, 8, sf::Color::Black, sf::Color::Blue);

    pawn* testPawn = new pawn(.75, 0, 2, 1, sf::Color::Red, &b);

    testTile.setpPawn(testPawn);

    if (testTile.getpPawn() != testPawn)
    {
        window.close();
        delete testPawn;
        throw std::runtime_error("FAILED: Pawn setter OR getter failed");
    }

    delete testPawn;


    // Close the window
    window.close();

    std::cout << "Tile Display Test PASSED." << std::endl;
}