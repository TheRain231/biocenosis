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
    int hp;
    int age;
    pair<float, float> position;
    const sf::Vector2<float> size = sf::Vector2f(WINDOW_HEIGHT / FIELD_HEIGHT, WINDOW_WIDTH / FIELD_WIDTH);
    sf::Sprite sprite;
    sf::Texture texture;
    void reset_position();
public:
    Entity(int hp, int age, float x, float y, const string& texture_name);
    void random_move(int range);
    sf::Sprite getSprite();
    sf::Texture getTexture();
};
