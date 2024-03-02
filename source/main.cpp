#include <SFML/Graphics.hpp>
#include "entity.h"
#include "defines.h"
#include <list>


int main() {
    srand(time(0));

    vector<vector<int>> field(WINDOW_HEIGHT, vector<int>(WINDOW_WIDTH, 0));
    vector<Entity> entities;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    sf::Vector2f bgSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    sf::Texture background;
    background.loadFromFile("../textures/dirt.png");
    sf::Sprite spriteBG;
    spriteBG.setTexture(background);
    spriteBG.setPosition(0, 0);
    spriteBG.setScale(
            bgSize.x / spriteBG.getLocalBounds().width,
            bgSize.y / spriteBG.getLocalBounds().height);
    window.setFramerateLimit(FPS);

    for (int i = 0 ; i < COW_COUNT;i++){
        entities.push_back(Entity("cow.png"));
    }
    for (int i = 0 ; i < PIG_COUNT;i++){
        entities.push_back(Entity("pig.png"));
    }
    cout << entities.size() << endl;

    sf::Texture Rain1;
    Rain1.loadFromFile("../textures/rain.png");
    sf::RectangleShape RainBackground1(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    RainBackground1.setTexture(&Rain1);
    RainBackground1.setPosition(0, 0);

    sf::Texture Rain2;
    Rain2.loadFromFile("../textures/rain.png");
    sf::RectangleShape RainBackground2(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    RainBackground2.setTexture(&Rain2);
    RainBackground1.setPosition(0, -WINDOW_HEIGHT);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (RainBackground2.getPosition().y > WINDOW_HEIGHT) {
            RainBackground2.setPosition(0, -WINDOW_HEIGHT);
        }

        if (RainBackground1.getPosition().y > WINDOW_HEIGHT) {
            RainBackground1.setPosition(0, -WINDOW_HEIGHT);
        }
        RainBackground2.move(0, RAIN_SPEED);
        RainBackground1.move(0, RAIN_SPEED);

        window.clear();
        window.draw(spriteBG);
        window.draw(RainBackground2);
        window.draw(RainBackground1);

        for (int i = 0; i < entities.size(); i++) {
            entities[i].random_move(100);
            window.draw(entities[i].getSprite());
        }

        window.display();
    }
    return 0;
}