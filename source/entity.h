#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "defines.h"
using namespace std;

class Entity {
private:
    const sf::Vector2<float> size = sf::Vector2f(WINDOW_HEIGHT / FIELD_HEIGHT, WINDOW_WIDTH / FIELD_WIDTH);
public:
    int hp;
    int age;
    pair<float, float> position;
    sf::Texture texture;
    sf::Sprite sprite;
    Entity(int hp, int age, float x, float y, const string& texture_name);

    void reset_position();

    void random_move(int range);
};
