//
// Created by Андрей Степанов on 05.03.2024.
//

#include "travoyadny.h"

Travoyadny::Travoyadny(string textureName, int id) : Entity(textureName, id) {
    hp = 100;
    hunger = 20;
}
