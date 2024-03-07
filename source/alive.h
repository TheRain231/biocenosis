#include "entity.h"

class Alive: public Entity {

    int hp;
    int hunger;
    void checkState();
    enum state{ ebatsa, eat, run };
    state currentState;
    void reset_position();
public:
    Alive(string textureName, int id);
    void random_move(int range);
    state getState() const;
    int find(vector<Alive> &alives) const;

    void move();
    void eblya(vector<Entity> &entities, string name, int &count) const;
    bool checkForEblya(Entity obj1, Entity obj2) const;
};