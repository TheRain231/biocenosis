// #pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
#include "defines.h"
using namespace std;

class Grass {
private:
    pair<float, float> position;
    sf::Texture texture;
    sf::Sprite sprite;
    const sf::Vector2<float> size = sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE);
    const string texture_name;
public:
    Grass(int x,int y,string texture_name);
    sf::Sprite getSprite() const;
    void reset_texture();
    bool isOverlap(const Grass& obj);
    void grow(vector<Grass> &arr);
};
