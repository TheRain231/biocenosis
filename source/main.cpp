#include <SFML/Graphics.hpp>
#include "defines.h"
#include "travoyadny.h"
#include "predator.h"
#include "grass.h"
#include <list>
#include "Rain.h"

int main() {
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    vector<Alive> alives;
    vector<pair<Alive&, Alive&>> ebutsya;
    vector<Grass> grass;
    int entityCounter = 0;
    int frames = 0;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    sf::Vector2f bgSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    sf::Texture background;
    background.loadFromFile("../textures/dirt.png");
    sf::Sprite spriteBG;
    spriteBG.setTexture(background);
    spriteBG.setPosition(0, 0);
    spriteBG.setScale(
            bgSize.x / spriteBG.getLocalBounds().width,
            bgSize.y / spriteBG.getLocalBounds().height);
    window.setFramerateLimit(FPS);

//    for (int i = 0 ; i < COW_COUNT;i++){
//        alives.push_back(Travoyadny("cow.png", entityCounter++));
//    }
    for (int i = 0; i < 2; i++) {
        alives.push_back(Alive("cow.png", entityCounter++));
    }

//    for (int i = 0 ; i < PIG_COUNT;i++){
//        alives.push_back(Travoyadny("pig.png", entityCounter++));
//    }


    Rain Rain_background;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(spriteBG);


        for (Alive &entity: alives) {
            if (entity.checkState() && entity.getCoolDawn() <= 0) {
                int id = entity.find(alives);
                for (Alive &entity2: alives) {
                    if (entity2.getId() == id && entity2.getCoolDawn() <= 0) {
                        ebutsya.push_back({entity, entity2});
                        entity.changeStateBeforeSex(entity2);
                        break;
                    }
                }
            }
        }
        //check for meeting ? delete + born + change state + new CD : move
        vector<pair<Alive&, Alive&>> ebutsya_new;
        for (pair<Alive&, Alive&> &bothEntity: ebutsya) {
            if (bothEntity.first.checkForEblya(bothEntity.second)) {
                bothEntity.first.changeStateAfterSex(bothEntity.second);
                bothEntity.first.setDefaultCoolDown();
                bothEntity.second.setDefaultCoolDown();
                bothEntity.first.eblya(alives, bothEntity.first.getTextureName(), entityCounter);

            } else {
                bothEntity.first.move(bothEntity.second);
                ebutsya_new.push_back(bothEntity);
            }
        }
        ebutsya.clear();
        for (auto &bothEnyties: ebutsya_new) {
            ebutsya.push_back(bothEnyties);
        }


        if (Rain_background.get_status() && grass.size()<GRASS_COUNT && frames%5==0){
            grass.push_back(Grass(rand()%15+1,rand()%15+1));
        }

//        frames++;
//        for(int i = grass.size()-1; i > 0 ; i--){
//            for(int j = i + 1;j < grass.size(); j++){
//                if(grass[i].isOverlap(grass[j])){
//                    // grass.erase(grass.end()-i); А ЗДЕСЬ КАК ТО УДАЛЯЙТЕ I-ый элемент, я ебу?
//                    break;
//                }
//            }
//            if(frames%Grass_Time==0 && grass.size()<GRASS_COUNT){
//                frames=0;
//                grass[i].grow(grass);
//            }
//            grass[i].reset_texture();
//            window.draw(grass[i].getSprite());
//        }


        for (Alive &entity: alives) {

           if (entity.checkState()) {
                entity.random_move(50);
            }

           cout << entity.getState() << " ";
            entity.decreaseCoolDown();
            //entity.reset_texture();
            window.draw(entity.getSprite());
        }
        cout << '\n';

//        for (auto &entity: ebutsya) {
//            try {
//            //Add check for state
//            //if (entity.checkState()) {
//            //entity.random_move(50);
//            entity.first.decreaseCoolDown();
//            entity.first.reset_texture();
//            window.draw(entity.first.getSprite());
//
//            entity.second.decreaseCoolDown();
//            entity.second.reset_texture();
//            window.draw(entity.second.getSprite());}
//            catch(exception) {
//
//            }
//            //}
//
//        }


        if (Rain_background.rain_update()) {
            Rain_background.move(RAIN_SPEED);
            window.draw(Rain_background.get_sprite1());
            window.draw(Rain_background.get_sprite2());
        }


        window.display();
    }

    return 0;
}