#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900
#define WINDOW_TITLE "Best Game"
#define FPS 20

//ТО ЧТО НАДО УДАЛИТЬ ПОСЛЕ

#define ENTITY_SIZE 0.1

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    sf::Vector2f targetSize(WINDOW_HEIGHT, WINDOW_WIDTH);

    sf::Texture background;
    background.loadFromFile("../textures/background.png");
    sf::Sprite spriteBG;
    spriteBG.setTexture(background);
    spriteBG.setPosition(0, 0);
    spriteBG.setScale(
            targetSize.x / spriteBG.getLocalBounds().width,
            targetSize.y / spriteBG.getLocalBounds().height);

    sf::Texture polar_bear;
    polar_bear.loadFromFile("../textures/polar_bear.png");

    sf::Texture wolf;
    wolf.loadFromFile("../textures/wolf.png");

    sf::Texture pig;
    pig.loadFromFile("../textures/pig.png");


    window.setFramerateLimit(FPS);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(spriteBG);
        window.display();
    }
    return 0;
}