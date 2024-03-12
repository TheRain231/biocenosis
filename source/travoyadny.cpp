#include "travoyadny.h"

Travoyadny::Travoyadny(string textureName, int id) : Alive(textureName, id) { }

Travoyadny::Travoyadny(float x, float y,string textureName, int id) : Alive(x, y, textureName, id) { }