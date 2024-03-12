#include "grass.h"
#include <iostream>
#include <utility>
using namespace std;

Grass::Grass(int x,int y,string texture_name): texture_name(std::move(texture_name)){
    // int x = rand()%WINDOW_WIDTH;
    // int y = rand()%WINDOW_HEIGHT;
    position = pair<float, float>(x, y);
    reset_texture();
    sprite.setTexture(texture);
    sprite.setPosition(position.first/15*WINDOW_WIDTH, position.second/15*WINDOW_HEIGHT);
    sprite.setScale(
            (WINDOW_WIDTH/15) / sprite.getLocalBounds().width,
            (WINDOW_HEIGHT/15) / sprite.getLocalBounds().height);
}
sf::Sprite Grass::getSprite() const{
    return sprite;
}
void Grass::reset_texture() {
    texture.loadFromFile("../textures/" + texture_name);
    sprite.setTexture(texture);
}
void Grass::grow(vector<Grass> &arr) const{
    switch (rand()%4) {
        case(0):if(position.first<15){arr.push_back(Grass(position.first+1,position.second,"grass.png"));break;}
        case(1):if(position.second<15){arr.push_back(Grass(position.first,position.second+1,"grass.png"));break;}
        case(2):if(position.first>0){arr.push_back(Grass(position.first-1,position.second,"grass.png"));break;}
        case(3):if(position.second>0){arr.push_back(Grass(position.first,position.second-1,"grass.png"));break;}
    }

}
bool Grass::isOverlap(const Grass& obj){
    return (position.first== obj.position.first && position.second == obj.position.second);
}