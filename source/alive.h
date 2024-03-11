#include "entity.h"

class Alive: public Entity {

    int hp;
    int hunger;
    void checkState();
    enum state{ ebatsa, eat, run };
    int coolDown = 50;

    state currentState;
    void reset_position();
    bool checkForEblya(Entity obj1, Entity obj2) const;

public:
    Alive(string textureName, int id);
    void random_move(int range);
    state getState() const;
    int find(vector<Alive> &alives) const;
    void eblya(vector<Entity> &entities, string name, int &count) const;
    void move();
    void decreaseCoolDown();
};