#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class Entity {
public:
    int hp;
    int age;
    pair<float, float> position;
    sf::Texture texture;
    sf::Sprite sprite;
    Entity(int hp, int age, float x, float y, const string& texture_name);

    void reset_position(){
        sprite.setPosition(position.first, position.second);
    }
};
