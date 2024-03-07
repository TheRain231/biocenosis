#include "entity.h"
#include <queue>


class Travoyadny: public Entity {
private:


    int hp;
    int hunger;

    void checkState();
    int BFS(int x, int y);
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

public:
    Travoyadny(string textureName, int id);
    void move();
    void eblya(vector<Entity> &entities, string name, int &count) const;
    bool checkForEblya(Entity obj1, Entity obj2) const;

};

