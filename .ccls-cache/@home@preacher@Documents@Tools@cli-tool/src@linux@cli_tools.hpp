#ifndef CLI_TOOLS_HPP
#define LINUX
#ifdef LINUX 

#include <vector>

namespace clts {
    enum color {
       red,
       blue,
       green,
       lightBlue,
    };
    
    // These functions need a windows and a linux version

    void setup();
    void pos(int x, int y);
    void setColor(color color);
    void getTerminalSize(int& posXOut, int& posXout);

    class pain {
    public:
        /*# pain**(posX, posY, sizeX, sizeY)**
          - **posX** is the X position of the pain *starting at 0* 
          - **posY** is the Y position of the pain *starting at 0* 
          - **sizeX** is the scail along the X Axis *this has to be greater then 5* 
          - **sizeY** is the scail along the Y Axis *this has to be greater then 5* 
          - **Layer** is the z depth of the pain. with *0 being the lowest* 
        */ 

        pain(int posX, int posY, int sizeX, int sizeY, int layer);
        
        // text buffer of pain
        const char* buffer;
        
        // This is the id for the pain for the masterPain.
        int id;

        // This is the layer that the pain will display
        int painLayer;

        // Position of pain
        int painPosX;
        int painPosY;
        // size of pain
        int painSizeX;
        int painSizeY;
        
        bool isActive;

        int getLayer()  { return painLayer; }
        int getPosX()   { return painPosX; }
        int getPosY()   { return painPosY; }
        int getSizeX()  { return painSizeX; }
        int getSizeY()  { return painSizeY; }
        int getid()     { return id; }

        bool getIsActive();

        void write(const char* current);
        void moveCursor(int posX, int posY);

        ~pain(){}
    };


    class masterPain {
    private:
        int painSizeX;
        int painSizeY;
        pain* pains[100];

        void refreshMasterPainSize();

    public:
        void update();
        void removePain(int id);
        pain* addPain(pain* addedPain);
        pain* getActivePain();
        pain* setActivePain(int id);
        pain* createPain(int posX, int posY,int sizeX,int sizeY, int layer);
        pain** getPainList();
        int getSizeX();
        int getSizeY();

    };


}
#endif // !LINUX 
#endif // !CLI_TOOLS_HPP 
