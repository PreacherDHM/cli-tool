#ifndef CLI_TOOLS_HPP
#define LINUX
#ifdef LINUX 
namespace clts {
    enum color {
       red,
       blue,
       green,
    };
    
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
        const char buffer;
        
        // This is the id for the pain for the masterPain.
        int id;

        // Position of pain
        int painPosX;
        int painPosY;
        // size of pain
        int sizeX;
        int sizeY;

        void write(const char* current);
        void moveCursor(int posX, int posY);

        ~pain(){}
    };


    class masterPain {
    private:
        int sizeX;
        int sizeY;

        void refreshMasterPainSize();

    public:
        void update();
        void addPain(pain* addedPain);
        void removePain(int id);
        pain getActivePain();
        pain setActivePain(int id);
        int getSizeX();
        int getSizeY();

    };

    // These functions need a windows and a linux version

    void setup();
    void pos(int x, int y);
    void setColor(color color);
    pain createPain(int posX, int posY,int sizeX,int sizeY, int layer);
    void getTerminalSize(int& posXOut, int& posXout);

}
#endif // !LINUX 
#endif // !CLI_TOOLS_HPP 
