#include "cli_tools.hpp"
#include <asm-generic/ioctls.h>
#include <cstddef>
#include <iostream>

// Linux Console imports
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

//------------------------ Master Functions ---------------------
//  These functions need to be rewriten for each operating system 

void clts::setup(){}
void clts::pos(int x, int y){
    std::cout << "\e["<<x<<";"<<y <<"H";
}
void clts::setColor(clts::color color){

}

void clts::getTerminalSize(int& posXOut, int& posYOut) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
}
//---------------------------------------------------------------

//------------------------- Pain Functions ----------------------

clts::pain::pain(int posX, int posY, int sizeX, int sizeY, int layer) :
    painPosX(posX), painPosY(posY), painSizeX(sizeX),
    painSizeY(sizeY), painLayer(layer) {}

void clts::pain::write(const char* current) {
    buffer = current;
}
void clts::pain::moveCursor(int posX, int posY) {
    int screenPositionX = posX + painPosX;
    int screenPositionY = posY + painPosY;
    pos(screenPositionX, screenPositionY);
}
//---------------------------------------------------------------


//---------------------- MasterPain Functions -------------------
void clts::masterPain::refreshMasterPainSize() {}

clts::pain* clts::masterPain::addPain(pain* addedPain) {

    for (size_t i = 0; i < 100; i++) {
        if(pains[i] == nullptr) {
            pains[i] = addedPain;
            addedPain->id = i;
            return addedPain;
        }
    }
    // if nullptr then pains[] is full
    return nullptr;
}

void clts::masterPain::removePain(int id) {
    pain* pain = pains[id];
    pains[id] = nullptr;
    delete pain;
}

clts::pain* clts::masterPain::getActivePain() {
    for (size_t i = 0;  i < 100;  i++) {
        if(pains[i]->isActive)
            return pains[i];
    }
    // no pain is active.
    return nullptr;
}

clts::pain* clts::masterPain::setActivePain(int id) {
    pains[id]->isActive = true;
    return pains[id];
}

clts::pain* clts::masterPain::createPain(int posX, int posY, int sizeX, int sizeY, int layer){
    clts::pain* pain = new clts::pain(posX,posY,sizeX,sizeY,layer);
    // if nullptr painBuffer full
    return addPain(pain);
}

clts::pain** clts::masterPain::getPainList() { return pains; }
int clts::masterPain::getSizeX() { return painSizeX; }
int clts::masterPain::getSizeY() { return painSizeY; }

//---------------------------------------------------------------
