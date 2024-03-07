#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
#include <string>
#include "defines.h"
using namespace std;

class Entity {
private:
    const sf::Vector2<float> size = sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE);
    sf::Texture texture;
    const string texture_name;
    int id;
protected:
    pair<float, float> position;
    sf::Sprite sprite;
public:
    static vector<vector<int>> field;
    Entity(string texture_name, int id);
    void reset_texture();
    sf::Sprite getSprite() const;
    string getTextureName() const;
    int getId() const;
    pair<float, float> getPosition() const;
};
