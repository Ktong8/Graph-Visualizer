#include <SFML/Graphics.hpp>
#include <iostream>
#include "graph.hpp"
#include "node.hpp"

using namespace std;

sf::Font font;
const string font_fam = "arial.ttf";
const int node_radius = 80.f;
const int font_size = 60.f;

void renderNode(sf::RenderWindow &window, Node node) {
    sf::CircleShape circ(node_radius);
    circ.setPosition(node.getX(), node.getY());
    circ.setFillColor(sf::Color::White);
    sf::Text val{to_string(node.getVal()), font, font_size};
    val.setPosition(node.getX() + node_radius - font_size / 2.f, node.getY() + node_radius - font_size / 2.f);
    val.setFillColor(sf::Color::Black);
    window.draw(circ);
    window.draw(val);
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
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Node node{2,2,50};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        renderNode(window, node);
        //window.draw(shape);
        window.display();
    }

    return 0;
}