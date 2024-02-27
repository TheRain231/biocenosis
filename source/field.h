#pragma once
#include <vector>
#include "entity.h"
using namespace std;



class Field{
private:
    vector<vector<Entity>> field;
public:
    Field(): field(vector<vector<Entity>>(FIELD_HEIGHT, vector<Entity>(FIELD_WIDTH, Entity(0, 0, 0, 0, "")))) {}
    Field(Entity entitiy): field(vector<vector<Entity>>(FIELD_HEIGHT, vector<Entity>(FIELD_WIDTH, entitiy))) {}
};