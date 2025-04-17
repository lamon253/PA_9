#include  "pawn.hpp"
#include  "board.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "checkers");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rectangle(sf::Vector2f{100,100});

    //tile t(50,200,200,sf::Color::Blue);
    board b(1000,1000,8,8, sf::Color::Black, sf::Color::Blue);
    pawn* p = new pawn(.75, 0, 2, 1, sf::Color::Red, &b);
    pawn* p2 = new pawn(.75, 1, 3, 1, sf::Color::Blue, &b);

    shape.setFillColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition({ 0,0 });
    rectangle.setSize({100,100});
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            p->tryMove(2, 4);
        window.clear();
        std::cout << p->getPos().x << p->getPos().y << std::endl;
        b.drawBoard(&window);
        window.display();
    }
}