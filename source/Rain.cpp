#include "Rain.h"
#include "defines.h"
#include <random>

sf::Sprite Rain::get_sprite1() const{
    return sprite1;
}
sf::Sprite Rain::get_sprite2() const{
    return sprite2;
}

void Rain::move(int value){
    sprite1.setPosition(0, sprite1.getPosition().y+value);
    sprite2.setPosition(0, sprite2.getPosition().y+value);
    if (sprite1.getPosition().y > WINDOW_HEIGHT) {
        sprite1.setPosition(0, -WINDOW_HEIGHT);
    }

    if (sprite2.getPosition().y > WINDOW_HEIGHT) {
        sprite2.setPosition(0, -WINDOW_HEIGHT);
    }
}

Rain::Rain() {
    set_texture();
    sprite1.setTexture(texture);
    sprite2.setTexture(texture);
    sprite1.setPosition(0,0);
    sprite2.setPosition(0,-WINDOW_HEIGHT);
    sprite1.setScale(sf::Vector2f (WINDOW_WIDTH, 2*WINDOW_HEIGHT).x / sprite1.getLocalBounds().width,sf::Vector2f (WINDOW_WIDTH, WINDOW_HEIGHT).y / sprite1.getLocalBounds().height);
    sprite2.setScale(sf::Vector2f (WINDOW_WIDTH, 2*WINDOW_HEIGHT).x / sprite1.getLocalBounds().width,sf::Vector2f (WINDOW_WIDTH, WINDOW_HEIGHT).y / sprite1.getLocalBounds().height);
}

void Rain::set_texture() {
    texture.loadFromFile("textures/rain.png");
}

int Rain::rain_update(){
    if (rain_coldown++>0){
        if (rain_coldown<rain_time){
            return 1;
        }
        else{
            rain_time=rand()%40+20;
            rain_coldown=-rand()%40-20;
        }
    }
    return 0;
}

bool Rain::get_status() const{
    return rain_coldown>0;
}