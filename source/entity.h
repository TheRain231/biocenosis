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
    enum state{ ebatsa, eat, run };
    state currentState;
    pair<float, float> position;
    const sf::Vector2<float> size = sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE);
    sf::Sprite sprite;
    sf::Texture texture;
    const string texture_name;
    void reset_position();
    int id;
public:
    static vector<vector<int>> field;
    Entity(string texture_name, int id);
    void random_move(int range);
    void reset_texture();
    sf::Sprite getSprite() const;
    string getTextureName() const;
    int getId() const;
    pair<float, float> getPosition() const;
    state getState() const;
    int find(Entity obj1, vector<Entity> &entities) const;
};
