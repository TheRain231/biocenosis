#include <SFML/Graphics.hpp>
#include "field.h"
#include "entity.h"
#include "defines.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    sf::Vector2f bgSize(WINDOW_HEIGHT, WINDOW_WIDTH);

    sf::Texture background;
    background.loadFromFile("textures/background.png");
    sf::Sprite spriteBG;
    spriteBG.setTexture(background);
    spriteBG.setPosition(0, 0);
    spriteBG.setScale(
            bgSize.x / spriteBG.getLocalBounds().width,
            bgSize.y / spriteBG.getLocalBounds().height);
    window.setFramerateLimit(FPS);

    Entity cow(1, 1, 100, 120, "cow.png");
    Entity pig(1, 1, 100, 120, "pig.png");
    Entity wolf(1, 1, 100, 120, "wolf.png");

    while (window.isOpen()) {
        srand(time(0));
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(spriteBG);

        cow.random_move(20);
        pig.random_move(20);
        wolf.random_move(20);

        window.draw(cow.getSprite());
        window.draw(pig.getSprite());
        window.draw(wolf.getSprite());

        window.display();
    }
    return 0;
}