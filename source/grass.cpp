#include "grass.h"
#include <iostream>
#include <utility>
using namespace std;

Grass::Grass(int x,int y){
    position = pair<float, float>(x, y);
    reset_texture();
    sprite.setPosition(position.first/15*WINDOW_WIDTH, position.second/15*WINDOW_HEIGHT);
    sprite.setScale(
            (WINDOW_WIDTH/15) / sprite.getLocalBounds().width,
            (WINDOW_HEIGHT/15) / sprite.getLocalBounds().height);
}
sf::Sprite Grass::getSprite() const{
    return sprite;
}
void Grass::reset_texture() {
    texture.loadFromFile("../textures/grass.png");
    sprite.setTexture(texture);
}
void Grass::grow(vector<Grass> &arr) const{
    switch (rand()%4) {
        case(0):if(position.first<15){arr.push_back(Grass(position.first+1,position.second));break;}
        case(1):if(position.second<15){arr.push_back(Grass(position.first,position.second+1));break;}
        case(2):if(position.first>0){arr.push_back(Grass(position.first-1,position.second));break;}
        case(3):if(position.second>0){arr.push_back(Grass(position.first,position.second-1));break;}
    }

}
bool Grass::isOverlap(const Grass& obj){
    return (position.first== obj.position.first && position.second == obj.position.second);
}