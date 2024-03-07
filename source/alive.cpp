#include "alive.h"

Alive::Alive(string textureName, int id) : Entity(textureName, id) {
    hp = 100;
    hunger = 20;
}

void Alive::random_move(int range) {
    position.first = rand() % range - range/2 + position.first;
    position.second = rand() % range - range/2 + position.second;
    reset_position();
}

void Alive::reset_position() {
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

Alive::state Alive::getState() const {
    return Alive::currentState;
}

int Alive::find(vector<Alive> &alives) const {
    int minId = -1;
    float minDistant = 1000000000;
    for (Alive& entity: alives) {
        if (this->getTextureName() == entity.getTextureName() && this->getId()!=entity.getId() && entity.getState()!=state::ebatsa) {
            pair<float, float> posObj1 = this->getPosition(), posEntity = entity.getPosition();
            float dist = sqrt(pow(posObj1.first-posEntity.first, 2) + pow(posObj1.second-posEntity.second, 2));
            if (dist<minDistant) {
                minDistant = dist;
                minId = entity.getId();
            }
        }
    }
    return minId;
}

void Alive::eblya(vector<Entity> &entities, std::string name, int &count) const {
    entities.push_back(Alive(name, count++));
}

bool Alive::checkForEblya(Entity obj1, Entity obj2) const {
    return obj1.getSprite().getGlobalBounds().intersects(obj2.getSprite().getGlobalBounds());
}
