#include <SFML/Graphics.hpp>
#include "defines.h"

class Rain {
public:
    Rain();
    void move(int value);
    sf::Sprite get_sprite1() const;
    sf::Sprite get_sprite2() const;
    void set_texture();
    int rain_update();

private:
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Texture texture;
    long long rain_time=1;
    long long rain_coldown=1;
};


