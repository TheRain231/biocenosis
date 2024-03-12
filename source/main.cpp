#include <SFML/Graphics.hpp>
#include "defines.h"
#include "travoyadny.h"
#include "predator.h"
#include "grass.h"
#include <list>


int main() {
    srand(time(0));

    vector<Alive> alives;
    vector<pair<Alive, Alive>> ebutsya;
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

    for (int i = 0 ; i < COW_COUNT;i++){
        alives.push_back(Travoyadny("cow.png", entityCounter++));
    }

    for (int i = 0 ; i < PIG_COUNT;i++){
        alives.push_back(Travoyadny("pig.png", entityCounter++));
    }

    for(int i=0;i<10;i++){
        grass.push_back(Grass((rand()%15+1),(rand()%15+1),"grass.png"));
    }

    sf::Texture Rain1;
    Rain1.loadFromFile("../textures/rain.png");
    sf::RectangleShape RainBackground1(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    RainBackground1.setTexture(&Rain1);
    RainBackground1.setPosition(0, 0);

    sf::Texture Rain2;
    Rain2.loadFromFile("../textures/rain.png");
    sf::RectangleShape RainBackground2(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    RainBackground2.setTexture(&Rain2);
    RainBackground1.setPosition(0, -WINDOW_HEIGHT);
    while (window.isOpen()) {
        frames++;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (RainBackground2.getPosition().y > WINDOW_HEIGHT) {
            RainBackground2.setPosition(0, -WINDOW_HEIGHT);
        }

        if (RainBackground1.getPosition().y > WINDOW_HEIGHT) {
            RainBackground1.setPosition(0, -WINDOW_HEIGHT);
        }
        RainBackground2.move(0, RAIN_SPEED);
        RainBackground1.move(0, RAIN_SPEED);

        window.clear();
        window.draw(spriteBG);
        window.draw(RainBackground2);
        window.draw(RainBackground1);

        // add Call down check
        for (Alive &entity: alives) {
            if (entity.checkState()) {
                int id = entity.find(alives);
                for (Alive &entity2: alives) {
                    if (entity2.getId() == id) {
                            ebutsya.push_back({entity, entity2});
                            entity.changeStateBeforeSex(entity2);
                            break;
                        }
                }
            }
        }
        //check for meeting ? delete + born + change state + new CD : move
        for (pair<Alive, Alive> &bothEntity: ebutsya) {
            if (bothEntity.first.checkForEblya(bothEntity.second)) {

                bothEntity.first.eblya(alives, bothEntity.first.getTextureName(), entityCounter);
                bothEntity.first.changeStateAfterSex(bothEntity.second);
                //ot andreya: delete gotov
                //ot andreya: new cd gotov
            }
            else{
                //ot andreya: move gotov
            }
        }

        if(frames%10==0&&grass.size()<GRASS_COUNT){
            frames=0;
            grass[(rand()%(grass.size()-1))].grow(grass);
        }
        for(int i=grass.size()-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(grass[i].isOverlap(grass[j])){
                    // grass.erase(grass.end()-i); А ЗДЕСЬ КАК ТО УДАЛЯЙТЕ I-ый элемент, я ебу?
                    break;
                }
            }
            grass[i].reset_texture();
            window.draw(grass[i].getSprite());
        }
        



        for (Alive& entity : alives) {
            //Add check for state
            if (entity.checkState()) {
                entity.random_move(50);
                entity.decreaseCoolDown();
                entity.reset_texture();
                window.draw(entity.getSprite());
            }

        }





        window.display();
    }
    return 0;
}