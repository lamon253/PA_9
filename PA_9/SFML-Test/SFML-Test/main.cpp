#include  "board.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rectangle(sf::Vector2f{100,100});

    //tile t(50,200,200,sf::Color::Blue);
    board b(1000,1000,10,10, sf::Color::Red, sf::Color::Blue);

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

        window.clear();
        //window.draw(shape);
        //window.draw(rectangle);
        //t.drawTile(&window);
        b.drawBoard(&window);
        window.display();
    }
}