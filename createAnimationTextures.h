//
// Created by Guillen Steulet on 31.10.23.
//

#ifndef EPI_C_CREATEANIMATIONTEXTURES_H
#define EPI_C_CREATEANIMATIONTEXTURES_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

std::vector<sf::Texture> createAnimationTextures(const std::string& spriteSheetPath, int frameWidth, int frameHeight);


#endif //EPI_C_CREATEANIMATIONTEXTURES_H
