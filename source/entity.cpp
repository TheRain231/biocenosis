#include "entity.h"
#include <iostream>
#include <utility>

Entity::Entity(string texture_name): texture_name(std::move(texture_name)){
    int x = rand()%WINDOW_WIDTH;
    int y = rand()%WINDOW_HEIGHT;
    position = pair<float, float>(x, y);
    reset_texture();
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

sf::Sprite Entity::getSprite() const{
    return sprite;
}

/*Entity::Entity(Entity const &right) {
    position = right.position;
    texture = right.texture;
    sprite = right.sprite;
    size = right.size;
}*/

void Entity::reset_texture() {
    texture.loadFromFile("../textures/" + texture_name);
    sprite.setTexture(texture);
}