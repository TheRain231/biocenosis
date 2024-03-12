#include "entity.h"
#include <iostream>
#include <utility>

vector<vector<int>> Entity::field = vector<vector<int>>(WINDOW_HEIGHT, vector<int>(WINDOW_WIDTH, 0));

Entity::Entity(string texture_name, int id): texture_name(std::move(texture_name)){
    int x = rand() % WINDOW_WIDTH;
    int y = rand() % WINDOW_HEIGHT;
    while (field[x][y] != 0){
        x = rand() % WINDOW_WIDTH;
        y = rand() % WINDOW_HEIGHT;
    }
    field[x][y] = id;
    this->id = id;
    position = pair<float, float>(x, y);
    reset_texture();
    sprite.setPosition(position.first, position.second);

    sprite.setScale(
            size.x / sprite.getLocalBounds().width,
            size.y / sprite.getLocalBounds().height);

}

Entity::Entity(float x, float y, string texture_name, int id): texture_name(std::move(texture_name)){
    while (field[x][y] != 0){
        x = rand() % WINDOW_WIDTH;
        y = rand() % WINDOW_HEIGHT;
    }
    field[x][y] = id;
    this->id = id;
    position = pair<float, float>(x, y);
    reset_texture();
    sprite.setPosition(position.first, position.second);

    sprite.setScale(
            size.x / sprite.getLocalBounds().width,
            size.y / sprite.getLocalBounds().height);

}

sf::Sprite Entity::getSprite() const{
    return sprite;
}

void Entity::reset_texture() {
    texture.loadFromFile("../textures/" + texture_name);
    sprite.setTexture(texture);
}

string Entity::getTextureName() const {
    return texture_name;
}
int Entity::getId() const {
    return id;
}

pair<float, float> Entity::getPosition() const {
    return position;
}