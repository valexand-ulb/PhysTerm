//
// Created by alex on 9/01/24.
//

#include "Debug.h"

void Debug::printCorners() {
    TerminalManager* tm = TerminalManager::getInstance();
    tm->drawPixel(vec2{-1.0f,-1.0f}.normalize(tm->getWidth(), tm->getHeight()), '0');
    tm->drawPixel(vec2{-1.0f,1.0f}.normalize(tm->getWidth(), tm->getHeight()), '1');
    tm->drawPixel(vec2{1.0f,-1.0f}.normalize(tm->getWidth(), tm->getHeight()), '2');
    tm->drawPixel(vec2{1.0f,1.0f}.normalize(tm->getWidth(), tm->getHeight()), '3');
}