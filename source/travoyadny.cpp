#include "travoyadny.h"

Travoyadny::Travoyadny(string textureName, int id) : Entity(textureName, id) {
    hp = 100;
    hunger = 20;
}

void Travoyadny::eblya(vector<Entity> &entities, std::string name, int &count) const {
    entities.push_back(Travoyadny(name, count++));
}

bool Travoyadny::checkForEblya(Entity obj1, Entity obj2) const {
    return obj1.getSprite().getGlobalBounds().intersects(obj2.getSprite().getGlobalBounds());
}

