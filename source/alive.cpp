#include "alive.h"

Alive::Alive(string textureName, int id) : Entity(textureName, id) {
    hp = ALIVE_HP;
    hunger = ALIVE_HUNGER;
    currentState = eat;
}

Alive::Alive(float x, float y, string textureName, int id) : Entity(x, y, textureName, id) {
    hp = ALIVE_HP;
    hunger = ALIVE_HUNGER;
    currentState = eat;
}

void Alive::random_move(int range) {
    position.first = rand() % range - range/2 + position.first;
    position.second = rand() % range - range/2 + position.second;
    reset_position();
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
    entities.push_back(Alive(position.first, position.second, "pig.png", count++));
}

void Alive::changeStateAfterSex(Alive &obj2) {
    this->currentState = eat;
    obj2.currentState = eat;
}
void Alive::changeStateBeforeSex(Alive &obj2) {
    this->currentState = ebatsa;
    obj2.currentState = ebatsa;
}

bool Alive::checkForEblya(Alive &obj2) const {
    if (getPosition().first <= obj2.getPosition().first && getPosition().second <= obj2.getPosition().second){
        if (getPosition().first + SPRITE_SIZE >= obj2.getPosition().first && getPosition().second + SPRITE_SIZE >= obj2.getPosition().second){
            return true;
        }
        return false;
    }
    if (getPosition().first + SPRITE_SIZE < obj2.getPosition().first && getPosition().second + SPRITE_SIZE < obj2.getPosition().second){
        return true;
    }
    return false;
}
//bool Alive::checkForEblya(Alive &obj2) const {
//    if (getPosition().first <= obj2.getPosition().first && getPosition().second <= obj2.getPosition().second){
//        if (getPosition().first + SPRITE_SIZE >= obj2.getPosition().first && getPosition().second + SPRITE_SIZE >= obj2.getPosition().second){
//            return true;
//        }
//        return false;
//    }
//    if (getPosition().first + SPRITE_SIZE < obj2.getPosition().first && getPosition().second + SPRITE_SIZE < obj2.getPosition().second){
//        return true;
//    }
//    return false;
//}

void Alive::decreaseCoolDown(){
    coolDown--;
}

bool Alive::checkName(Alive obj2) {
    return this->getTextureName() == obj2.getTextureName();
}

bool Alive::checkState() {
    return this->getState() != ebatsa;
}

bool Alive::checkId(Alive obj2) {
    return this->getId() == obj2.getId();
}

Alive::Alive(Alive const &right) : Entity(right.position.first, right.position.second, right.getTextureName(), right.getId()) {
    hp = right.hp;
    hunger = right.hunger;
    currentState = right.currentState;
}

void Alive::setDefaultCoolDown() {
    this->coolDown = CALL_DAWN_SEX;
}


void Alive::move(Alive& para) {
    float dx = 0, dy = 0;
    dx = (position.first + para.position.first) / 2;
    dy = (position.second + para.position.second) / 2;

    if (position.first < dx)
        position.first = TRAVOYADNYE_SPEED + position.first;
    else
        position.first =  position.first - TRAVOYADNYE_SPEED;
    if (position.second < dy)
        position.second = TRAVOYADNYE_SPEED + position.second;
    else
        position.second =  position.second - TRAVOYADNYE_SPEED;

    if (para.position.first < dx)
        para.position.first = TRAVOYADNYE_SPEED + para.position.first;
    else
        para.position.first =  para.position.first - TRAVOYADNYE_SPEED;
    if (para.position.second < dy)
        para.position.second = TRAVOYADNYE_SPEED + para.position.second;
    else
        para.position.second =  para.position.second - TRAVOYADNYE_SPEED;

    if (abs(position.first - para.position.first) < 10 && abs(position.second - para.position.second) < 10){
        para.position.first = position.first;
        para.position.second = position.second;
    }

    reset_position();
    para.reset_position();
}


int Alive::getCoolDawn() {
    return this->coolDown;
}