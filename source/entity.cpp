#include "entity.h"

Entity::Entity(int hp, int age, float x, float y, const string& texture_name){
    this->hp = hp;
    this->age = age;
    position = pair<float, float>(x, y);
    texture.loadFromFile("textures/" + texture_name);
    sprite.setTexture(texture);
    sprite.setPosition(position.first, position.second);

    sprite.setScale(
            size.x / sprite.getLocalBounds().width,
            size.y / sprite.getLocalBounds().height);
}

void Entity::reset_position() {
    if (position.first < 0){
        position.first = 0;
    } else if (position.first > WINDOW_WIDTH){
        position.first = WINDOW_WIDTH;
    }
    if (position.second < 0){
        position.second = 0;
    } else if (position.second > WINDOW_HEIGHT){
        position.second = WINDOW_HEIGHT;
    }
    sprite.setPosition(position.first, position.second);
}

void Entity::random_move(int range) {
    position.first = rand() % range - range/2 + position.first;
    position.second = rand() % range - range/2 + position.second;
    reset_position();
}

sf::Sprite Entity::getSprite() const{
    return this->sprite;
}


sf::Texture Entity::getTexture() const{
    return this->texture;
}