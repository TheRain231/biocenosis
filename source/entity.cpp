#include "entity.h"
#include <iostream>

Entity::Entity(string texture_name){

    int x = rand()%WINDOW_WIDTH;
    int y = rand()%WINDOW_HEIGHT;
    position = pair<float, float>(x, y);
    texture.loadFromFile("../textures/" + texture_name);
    sprite.setTexture(texture);
    sprite.setPosition(position.first, position.second);

    sprite.setScale(
            size.x / sprite.getLocalBounds().width,
            size.y / sprite.getLocalBounds().height);
}

void Entity::reset_position() {
    if (position.first < 0){
        position.first = 0;
    } else if (position.first > WINDOW_WIDTH-SPRITE_SIZE){
        position.first = WINDOW_WIDTH-SPRITE_SIZE;
    }
    if (position.second < 0){
        position.second = 0;
    } else if (position.second > WINDOW_HEIGHT-SPRITE_SIZE){
        position.second = WINDOW_HEIGHT-SPRITE_SIZE;
    }
    sprite.setPosition(position.first, position.second);
}

void Entity::random_move(int range) {
    position.first = rand() % range - range/2 + position.first;
    position.second = rand() % range - range/2 + position.second;
    reset_position();
}

sf::Sprite Entity::getSprite(){
    return this->sprite;
}