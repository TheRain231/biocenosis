#include <SFML/Graphics.hpp>
#include "field.h"
#include "entity.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Best Game"
#define FPS 10

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    sf::Vector2f bgSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    sf::Vector2f entitySize(WINDOW_HEIGHT / FIELD_HEIGHT, WINDOW_WIDTH / FIELD_WIDTH);

    sf::Texture background;
    background.loadFromFile("textures/background.png");
    sf::Sprite spriteBG;
    spriteBG.setTexture(background);
    spriteBG.setPosition(0, 0);
    spriteBG.setScale(
            bgSize.x / spriteBG.getLocalBounds().width,
            bgSize.y / spriteBG.getLocalBounds().height);

    sf::Texture polar_bear;
    polar_bear.loadFromFile("../textures/polar_bear.png");

    sf::Texture wolf;
    wolf.loadFromFile("../textures/wolf.png");

    window.setFramerateLimit(FPS);

    Entity cow(1, 1, 100, 120, "cow.png");
    Entity pig(1, 1, 100, 120, "pig.png");
    
    cow.sprite.setScale(
            entitySize.x / spriteBG.getLocalBounds().width,
            entitySize.y / spriteBG.getLocalBounds().height);
    pig.sprite.setScale(
            entitySize.x / spriteBG.getLocalBounds().width,
            entitySize.y / spriteBG.getLocalBounds().height);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(spriteBG);
        

        cow.position.first = rand() % 10 - 5 + cow.position.first;
        cow.position.second = rand() % 10 - 5 + cow.position.second;
        cow.reset_position();

        window.draw(cow.sprite);
        window.draw(pig.sprite);

        window.display();
    }
    return 0;
}