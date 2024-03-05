//
// Created by Андрей Степанов on 05.03.2024.
//
#include "entity.h"

class Travoyadny: public Entity {
private:

    enum state{ ebatsa, eat, run };
    int hp;
    int hunger;
    state currentState;
    void checkState();
    void find();

public:
    Travoyadny(string textureName, int id);
    void move();
};

