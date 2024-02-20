#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900
#define WINDOW_TITLE "Best Game"
#define FPS 20

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    sf::Texture background;
    background.loadFromFile("textures/background.png");
    sf::Sprite spriteBG;
    spriteBG.setTexture(background);
    spriteBG.setPosition(0, 0);
    window.setFramerateLimit(FPS);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        sf::Vector2f targetSize(WINDOW_HEIGHT, WINDOW_WIDTH);
        spriteBG.setScale(
                targetSize.x / spriteBG.getLocalBounds().width,
                targetSize.y / spriteBG.getLocalBounds().height);
        window.draw(spriteBG);
        window.display();
    }
    return 0;
}