/*
*/

#include "pawn.hpp"
#include "board.hpp"
#include "Test.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Test test;
    //test.TestSFMLWindowStatus();
    //test.TestTileDisplay();


    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "checkers");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rectangle(sf::Vector2f{100,100});

    //tile t(50,200,200,sf::Color::Blue);
    board b(1000,1000,8,8, sf::Color::Black, sf::Color::Blue);
    //pawn* p = new pawn(.75, 0, 2, 1, sf::Color::Red, &b);
    //pawn* p2 = new pawn(.75, 1, 3, 1, sf::Color::Blue, &b);

    std::vector<pawn*> pieces1; //player 1 pieces (top) in blue
    std::vector<pawn*> pieces2; //player 2 pieces (bottom) in red

    pawn* temp; //temp to help store pieces on startup

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((row + col) % 2 == 0)
            {
                temp = new pawn(0.75, col, row, 1, sf::Color::Blue, &b);
                pieces1.push_back(temp);
            }
        }
    }

    for (int row = 5; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((row + col) % 2 == 0)
            {
                temp = new pawn(0.75, col, row, 0, sf::Color::Red, &b);
                pieces2.push_back(temp);
            }
        }
    }

    shape.setFillColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition({ 0,0 });
    rectangle.setSize({100,100});

    int turn = 0;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            p->tryMove(2, 4);*/
        window.clear();
        //std::cout << p->getPos().x << p->getPos().y << std::endl;
        b.drawBoard(&window);
        window.display();

        if (turn++ % 2 == 0) //player 1 turn
        {
            std::string input;
            std::string input2;
            int tempRow = 0, tempCol = 0;
            int newRow = 0, newCol = 0;
            pawn* tempPawn = nullptr;
            do
            {
                cout << "Player 1 (Blue) Choose a Piece to Move (col row)" << endl;
                cin >> input;
                if (input.length() == 2 && isdigit(input[0]) && isdigit(input[1]))
                {
                    tempCol = input[0] - '0';
                    tempRow = input[1] - '0';
                    tempPawn = b.pieceSearch(tempCol, tempRow, pieces1);
                    if (tempPawn == nullptr)
                    {
                        cout << "Couldn't Find a Piece Here" << endl;
                    }
                    else
                    {
                        bool check = false;
                        do
                        {
                            cout << "Enter Where to Move the Piece" << endl;
                            cin >> input2;
                            if (input2.length() == 2 && isdigit(input2[0]) && isdigit(input2[1]))
                            {
                                newCol = input2[0] - '0';
                                newRow = input2[1] - '0';

                                if (!(check = tempPawn->tryMove(newCol, newRow)))
                                {
                                    cout << "Invalid Move try another" << endl;
                                }
                            }
                        } while (input2.length() != 2 || !isdigit(input2[0]) || !isdigit(input2[1]) || !check);
                    }
                }
            } while (input.length() != 2 || !isdigit(input[0]) || !isdigit(input[1]) || tempPawn == nullptr);
        }
        else //player 2 turn
        {
            std::string input;
            std::string input2;
            int tempRow = 0, tempCol = 0;
            int newRow = 0, newCol = 0;
            pawn* tempPawn = nullptr;
            do
            {
                cout << "Player 2 (Red) Choose a Piece to Move (col row)" << endl;
                cin >> input;
                if (input.length() == 2 && isdigit(input[0]) && isdigit(input[1]))
                {
                    tempCol = input[0] - '0';
                    tempRow = input[1] - '0';
                    tempPawn = b.pieceSearch(tempCol, tempRow, pieces2);
                    if (tempPawn == nullptr)
                    {
                        cout << "Couldn't Find a Piece Here" << endl;
                    }
                    else
                    {
                        bool check = false;
                        do
                        {
                            cout << "Enter Where to Move the Piece" << endl;
                            cin >> input2;
                            if (input2.length() == 2 && isdigit(input2[0]) && isdigit(input2[1]))
                            {
                                newCol = input2[0] - '0';
                                newRow = input2[1] - '0';

                                if (!(check = tempPawn->tryMove(newCol, newRow)))
                                {
                                    cout << "Invalid Move try another" << endl;
                                }
                            }
                        } while (input2.length() != 2 || !isdigit(input2[0]) || !isdigit(input2[1]) || !check);
                    }
                }
            } while (input.length() != 2 || !isdigit(input[0]) || !isdigit(input[1]) || tempPawn == nullptr);
        }
    }
}