#include <SFML/Graphics.hpp>
#include "entity.h"
#include "defines.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    sf::Vector2f bgSize(WINDOW_WIDTH, WINDOW_HEIGHT);

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
    sf::Texture Rain1;
    Rain1.loadFromFile("../textures/rain.png");
    sf::RectangleShape RainBackground1(sf::Vector2f(WINDOW_WIDTH,WINDOW_HEIGHT));
    RainBackground1.setTexture(&Rain1);
    RainBackground1.setPosition(0,0);

    sf::Texture Rain2;
    Rain2.loadFromFile("../textures/rain.png");
    sf::RectangleShape RainBackground2(sf::Vector2f(WINDOW_WIDTH,WINDOW_HEIGHT));
    RainBackground2.setTexture(&Rain2);
    RainBackground1.setPosition(0,-WINDOW_HEIGHT);

    while (window.isOpen()) {
        srand(time(0));
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (RainBackground2.getPosition().y>WINDOW_HEIGHT){
            RainBackground2.setPosition(0,-WINDOW_HEIGHT);
        }

        if (RainBackground1.getPosition().y>WINDOW_HEIGHT){
            RainBackground1.setPosition(0,-WINDOW_HEIGHT);
        }
        RainBackground2.move(0,RAIN_SPEED);
        RainBackground1.move(0,RAIN_SPEED);


        cow.random_move(20);
        pig.random_move(20);
        wolf.random_move(20);

        window.clear();
        window.draw(spriteBG);
        window.draw(RainBackground2);
        window.draw(RainBackground1);


        window.draw(cow.getSprite());
        window.draw(pig.getSprite());
        window.draw(wolf.getSprite());

        window.display();
    }
    return 0;
}