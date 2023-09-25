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
        //# pain**(posX, posY, sizeX, sizeY)**
        //  - **posX** is the X position of the pain *starting at 0*
        //  - **posY** is the Y position of the pain *starting at 0*
        //  - **sizeX** is the scail along the X Axis *this has to be greater then 5*
        //  - **sizeY** is the scail along the Y Axis *this has to be greater then 5*
        //  - **Layer** is the z depth of the pain. with *0 being the lowest*
        //

        pain(int posX, int posY, int sizeX, int sizeY, int layer);
        
        // text buffer of pain
        const char* buffer;

        // Position of pain
        int posX;
        int posY;
        // size of pain
        int sizeX;
        int sizeY;

        ~pain(){}
    };


    class masterPain {
    public:
        void update();
        void addPain(pain* addedPain);
        void removePain(int id);
        pain getActivePain();
        pain setActivePain(int id);

    };

    void setup();
    void pos(int x, int y);
    void write(const char* current, pain pain);
    void setColor(color color);
    pain createPain(int posX, int posY,int sizeX,int sizeY, int layer);

}
#endif // !LINUX
#endif // !CLI_TOOLS_HPP
