/*
* Description: This class contains the test cases for the Checker game application.
*
* Test.hpp
*/

#pragma once

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "tile.hpp"
#include "pawn.hpp"
#include "board.hpp"


class Test
{
public:
    void TestSFMLWindowStatus(); // Test if the SFML window works correctly.

    void TestTileDisplay();      // Test if tile is displayed correctly on the screen.

    void TestPawnPlacement();    // Test if pawns are placed correctly on the board.

    void TestPawnMovement();     // Test if pawns are moving correctly.

    void testBoardDisplay();     // Test if the board is displayed correctly.

    void TestTileInteraction();  // Test interactions between pawns and tiles.

private:

};
