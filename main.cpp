#include <SFML/Graphics.hpp>
#include <iostream>
#include "graph.hpp"
#include "node.hpp"

using namespace std;

sf::Font font;
const string font_fam = "arial.ttf";

void renderNode(sf::RenderWindow window, Node node) {
    sf::CircleShape circ(100.f);
    circ.setPosition(node.getX(), node.getY());
    circ.setFillColor(sf::Color::White);
    sf::Text val{to_string(node.getVal()), font, 24};
    val.setPosition(node.getX(), node.getY());
    val.setFillColor(sf::Color::Black);
}

int loadFont() {
    if (!font.loadFromFile(font_fam)) {
        cerr << "Error: Can't load font " << font_fam << "\n";
        return -1;
    }
    return 0;
}

int main()
{
    if (loadFont() != 0) {
        return -1; // exit with error if can't load font
    }
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}