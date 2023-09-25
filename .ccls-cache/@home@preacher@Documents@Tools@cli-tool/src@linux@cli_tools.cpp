#include "cli_tools.hpp"
#include <cstddef>

void clts::setup(){}
void clts::pos(int x, int y){}
void clts::setColor(clts::color color){}
void clts::write(const char*, pain pain){}
clts::pain clts::createPain(int posX, int posY, int sizeX, int sizeY, int layer){
return clts::pain(posX,posY,sizeX,sizeY,layer);
}
