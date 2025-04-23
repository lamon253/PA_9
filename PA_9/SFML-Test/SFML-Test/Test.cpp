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
        throw std::runtime_error("Tile Display Test FAILED: getRect() returned nullptr"); // Rectangle failed to be created
    }

    // Check if the position matches
    sf::Vector2f tilePos = testTile.getTilePos();

    if (tilePos.x != testX || tilePos.y != testY)
    {
        window.close();
        throw std::runtime_error("Tile Display Test FAILED: Tile position incorrect");
    }

    // Check if the rectangle size matches
    if (tileRect->getSize().x != tileSize || tileRect->getSize().y != tileSize)
    {
        window.close();
        throw std::runtime_error("Tile Display Test FAILED: Tile size incorrect");
    }

    // Check color fill-in
    if (tileRect->getFillColor() != testColor)
    {
        window.close();
        throw std::runtime_error("Tile Display Test FAILED: Tile color incorrect");
    }

    // Check drawing functionality
    window.clear(sf::Color::White);
    testTile.drawTile(&window);
    window.display();


    // 2. Test Pawn setter and getter
    board testBoard(1000, 1000, 8, 8, sf::Color::Black, sf::Color::Blue);

    pawn* testPawn = new pawn(.75, 0, 2, 1, sf::Color::Red, &testBoard);

    testTile.setpPawn(testPawn);

    if (testTile.getpPawn() != testPawn)
    {
        window.close();
        delete testPawn;
        throw std::runtime_error("Tile Display Test FAILED: Pawn setter OR getter failed");
    }

    delete testPawn;


    // Close the window
    window.close();

    std::cout << "Tile Display Test PASSED." << std::endl;
}


// Test if the board is generated & displayed correctly.
void Test::testBoardDisplay()
{
    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "Board Display Test");

    // Test window creation
    if (!window.isOpen())
    {
        throw std::runtime_error("Board Display Test FAILED: Failed to create SFML window");
    }

    // Create a board object
    board testBoard(1000, 1000, 8, 8, sf::Color::Black, sf::Color::Blue);

    // Verify board dimensions
    if (/*testBoard.tiles.size() != 8 || (testBoard.tiles.size() > 0 && testBoard.tiles[0].size() != 8)*/true)
    {
        throw std::runtime_error("Board Display Test FAILED: Board dimensions are incorrect");
    }

    // Verify colors are set correctly (since they're private, we can only check if the board draws)
    // Note: This would require either making these test functions friends or adding getters

    // Test drawBoard() function
    window.clear(sf::Color::White);
    testBoard.drawBoard(&window);
    window.display();

    // Check if the window is still open (didn't crash during drawing)
    if (!window.isOpen()) // Window crashed automatically
    {
        throw std::runtime_error("Board Display Test FAILED: Window closed unexpectedly during drawing");
    }

    // Wait for a few seconds to see the result
    sf::sleep(sf::seconds(2));

    window.close();

    std::cout << "Board Display Test PASSED." << std::endl;
}


// Test if pawns are moving correctly for diagonal movement.
void Test::TestPawnMovement()
{
    board testBoard(1000, 1000, 8, 8, sf::Color::Black, sf::Color::Blue);

    // Use a vector to store all the pawns on the board
    std::vector<pawn*> pieces;

    pawn* testPawn = new pawn(1.0f, 2, 2, true, sf::Color::Red, &testBoard);

    pieces.push_back(testPawn);

    // Test pawn movement
    int result = testPawn->tryMove(3, 3, pieces);

    // Result verification
    std::cout << "Movement Test " << (result == 1 ? "PASSED" : "FAILED") << std::endl; // Note for Review: We can use a ternary operator to simplify the if-else statement.
}


// Test if pawns are capturing correctly.
void Test::TestPawnCapture()
{
    board testBoard(1000, 1000, 8, 8, sf::Color::Black, sf::Color::Blue);
    std::vector<pawn*> pieces;

    // Place two test pawns watiting to be captured
    pawn* redPawn = new pawn(1.0f, 2, 2, true, sf::Color::Red, &testBoard);
    pawn* blackPawn = new pawn(1.0f, 3, 3, false, sf::Color::Black, &testBoard);

    pieces.push_back(redPawn);
    pieces.push_back(blackPawn);

    // Test capture by moving red pawn from (2,2) -> (4,4) over (3,3)
    int result = redPawn->tryMove(4, 4, pieces);

    // Verify the black pawn at (3,3) was captured, which should resulted in be removed from pieces vector
    bool blackCaptured = true;

    for (auto p : pieces) // Note for review: This is a range-based for loop, it iterates over all elements in the pieces vector.
    {
        if (p->getCol() == 3 && p->getRow() == 3)  // check if the pawn is still there
        {
            blackCaptured = false;
            break;
        }
    }

    std::cout << "Capture Move Test: "
        << ((result == 2 && blackCaptured) ? "PASSED" : "FAILED")
        << std::endl;
}