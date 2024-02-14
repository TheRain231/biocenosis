#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "BEST GAME EVER");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //тут начинается гейплей
        window.clear(sf::Color::Black);
        sf::Texture texture;
        texture.loadFromFile("textures/cow.png");
        sf::Sprite sprite;
        sprite.setTexture(texture);

        //размер
        sf::Vector2f targetSize(200.0f, 200.0f);
        sprite.setScale(
                targetSize.x / sprite.getLocalBounds().width,
                targetSize.y / sprite.getLocalBounds().height);

        window.draw(sprite);
        window.display();
    }
    return 0;
}