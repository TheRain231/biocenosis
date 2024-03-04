#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
#include "defines.h"
using namespace std;

class Entity {
private:

    pair<float, float> position;
    const sf::Vector2<float> size = sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE);
    sf::Sprite sprite;
    sf::Texture texture;
    const string texture_name;
    void reset_position();

public:

    Entity(string texture_name);
    void random_move(int range);
    void reset_texture();
    sf::Sprite getSprite() const;

};
