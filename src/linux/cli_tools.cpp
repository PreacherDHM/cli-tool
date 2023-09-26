#include "cli_tools.hpp"
#include <asm-generic/ioctls.h>
#include <iostream>

// Linux Console imports
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>


void clts::pain::write(const char* current) {
    buffer = current;
}
void clts::pain::moveCursor(int posX, int posY) {
    int screenPositionX = posX + painPosX;
    int screenPositionY = posY + painPosY;
    pos(screenPositionX, screenPositionY);
}

void clts::setup(){}
void clts::pos(int x, int y){
    std::cout << "\e["<<x<<";"<<y <<"H";
}
void clts::setColor(clts::color color){

}

void clts::getTerminalSize(clts::masterPain masterPain) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
}


clts::pain clts::createPain(int posX, int posY, int sizeX, int sizeY, int layer){
return clts::pain(posX,posY,sizeX,sizeY,layer);
}
