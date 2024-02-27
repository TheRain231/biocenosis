#include "entity.h"

Entity::Entity(int hp, int age, float x, float y, const string& texture_name){
    this->hp = hp;
    this->age = age;
    position = pair<float, float>(x, y);
    texture.loadFromFile("textures/" + texture_name);
    sprite.setTexture(texture);
    sprite.setPosition(position.first, position.second);
}