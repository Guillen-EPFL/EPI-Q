//
// Created by Guillen Steulet on 31.10.23.
//


#include <SFML/Graphics.hpp>
#include <vector>

std::vector<sf::Texture> createAnimationTextures(const std::string& spriteSheetPath, int frameWidth, int frameHeight) {
    std::vector<sf::Texture> animationTextures;
    sf::Texture spriteSheetTexture;

    if (!spriteSheetTexture.loadFromFile(spriteSheetPath)) {
        // Handle loading error
        return animationTextures;
    }

    // Calculate the number of frames in the x and y direction
    int framesX = spriteSheetTexture.getSize().x / frameWidth;
    int framesY = spriteSheetTexture.getSize().y / frameHeight;


    for (int i = 0; i < framesY; i++) {
        for (int j = 0; j < framesX; j++) {
            sf::IntRect frameRect(j * frameWidth, i * frameHeight, frameWidth, frameHeight);
            sf::Texture frameTexture;
            frameTexture.loadFromImage(spriteSheetTexture.copyToImage(), frameRect);
            animationTextures.push_back(frameTexture);
        }
    }

    return animationTextures;
}
