#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "createAnimationTextures.h"



const int MODEWIDTH = 1200;
const int MODEHEIGHT = 800;
const int CHARACTER_DIM = 128;


int main() {
    sf::RenderWindow window(sf::VideoMode(MODEWIDTH, MODEHEIGHT), "EPI-C");

    //load the textures
/*    sf::Texture characterTextureDown1;
    if (!characterTextureDown1.loadFromFile("/Users/guillen/CLionProjects/EPI-C/characterdown1.png")) {
        return 1;
    }
    sf::Texture characterTextureUp1;
    if (!characterTextureUp1.loadFromFile("/Users/guillen/CLionProjects/EPI-C/characterup1.png")) {
        return 1;
    }
    sf::Texture characterTextureLeft1;
    if (!characterTextureLeft1.loadFromFile("/Users/guillen/CLionProjects/EPI-C/characterleft1.png")) {
       return 1;
    }
    sf::Texture characterTextureRight1;
    if (!characterTextureRight1.loadFromFile("/Users/guillen/CLionProjects/EPI-C/characterright1.png")) {
        return 1;
    }*/

    std::vector<sf::Texture> animationTextures = createAnimationTextures("/Users/guillen/CLionProjects/EPI-C/spritesheet.png",
                                                                          128, 128);

    sf::Texture characterTextureDown1 = animationTextures[0];
    sf::Texture characterTextureUp1 = animationTextures[2];
    sf::Texture characterTextureLeft1 = animationTextures[4];
    sf::Texture characterTextureRight1 = animationTextures[6];

    sf::Sprite characterSprite(characterTextureDown1);
    characterSprite.setPosition(0, 0);

    float movementSpeed = 1.0f;  // Adjust the speed as needed

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Handle keyboard input for movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && characterSprite.getPosition().x > 0) {
            characterSprite.move(-movementSpeed, 0);
            characterSprite.setTexture(characterTextureLeft1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && characterSprite.getPosition().x < MODEWIDTH - CHARACTER_DIM) {
            characterSprite.move(movementSpeed, 0);
            characterSprite.setTexture(characterTextureRight1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && characterSprite.getPosition().y > 0) {
            characterSprite.move(0, -movementSpeed);
            characterSprite.setTexture(characterTextureUp1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && characterSprite.getPosition().y < MODEHEIGHT - CHARACTER_DIM) {
            characterSprite.move(0, movementSpeed);
            characterSprite.setTexture(characterTextureDown1);
        }

        window.clear();
        window.draw(characterSprite);
        window.display();
    }

    return 0;
}



