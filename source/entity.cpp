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
    currentState = state::eat;
    field[x][y] = id;
    this->id = id;
    position = pair<float, float>(x, y);
    reset_texture();
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
Entity::state Entity::getState() const {
    return Entity::currentState;
}

int Entity::find(Entity obj1, vector<Entity> &entities) const {
    int minId = -1;
    float minDistant = 1000000000;
    for (Entity& entity: entities) {
        if (obj1.getTextureName() == entity.getTextureName() && obj1.getId()!=entity.getId() && entity.getState()!=state::ebatsa) {
            pair<float, float> posObj1 = obj1.getPosition(), posEntity = entity.getPosition();
            float dist = sqrt(pow(posObj1.first-posEntity.first, 2) + pow(posObj1.second-posEntity.second, 2));
            if (dist<minDistant) {
                minDistant = dist;
                minId = entity.getId();
            }
        }
    }
    return minId;
}



