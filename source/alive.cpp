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

void Alive::eblya(vector<Alive> &entities, std::string name, int &count) const {
    entities.push_back(Alive(name, count++));
}
void Alive::changeStateAfterSex(Alive &obj2) {
    this->currentState = state::eat;
    obj2.currentState = state::eat;
}
void Alive::changeStateBeforeSex(Alive &obj2) {
    this->currentState = state::ebatsa;
    obj2.currentState = state::ebatsa;
}

bool Alive::checkForEblya(Alive obj2) const {
    return this->getSprite().getGlobalBounds().intersects(obj2.getSprite().getGlobalBounds());
}

void Alive::decreaseCoolDown(){
    coolDown--;
}

bool Alive::checkName(Alive obj2) {
    return this->getTextureName() == obj2.getTextureName();
}

bool Alive::checkState() {
    return this->getState() !=  state::ebatsa;
}

bool Alive::checkId(Alive obj2) {
    return this->getId() == obj2.getId();
}

Alive::Alive(Alive const &right) : Entity(right.getTextureName(), right.getId()) {
    hp = right.hp;
    hunger = right.hp;
}

void Alive::setDefaultCoolDown() {
    coolDown = CALL_DAWN_SEX;
}


void Alive::move(Alive& para) {
    float dx = 0, dy = 0;
    dx = (position.first + para.position.first) / 2;
    dy = (position.second + para.position.second) / 2;

    position.first = fmod(dx, TRAVOYADNYE_SPEED) + position.first;
    position.second = fmod(dy, TRAVOYADNYE_SPEED) + position.second;

    para.position.first = -fmod(dx, TRAVOYADNYE_SPEED) + para.position.first;
    para.position.second = -fmod(dy, TRAVOYADNYE_SPEED) + para.position.second;

    reset_position();
}