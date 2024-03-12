#include "entity.h"

class Alive: public Entity {

    int hp;
    int hunger;
    enum state{ ebatsa, eat, run };
    int coolDown = CALL_DAWN_SEX;

    state currentState;

public:
    bool checkForEblya(Alive obj2) const;
    bool checkState();
    bool checkName(Alive obj1);
    bool checkId(Alive obj2);
    Alive(string textureName, int id);
    Alive(float x, float y, string textureName, int id);
    Alive(Alive const &right);
    void random_move(int range);
    state getState() const;
    int find(vector<Alive> &alives) const;
    void eblya(vector<Alive> &entities, string name, int &count) const;
    void move(Alive& para);
    void decreaseCoolDown();
    void setDefaultCoolDown();
    void changeStateAfterSex(Alive &obj2);
    void changeStateBeforeSex(Alive &obj2);
    int getCoolDawn();
};