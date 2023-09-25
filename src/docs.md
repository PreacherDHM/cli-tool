# CLI Tools

CLI tools is a standerd set of tools that allow the user to create a nice TUI with 
basic functions.

## Tools 
These are tools that both windows and linux will have.

### Functions 
- **void setup()** : This function will setup the terminal.
- **void pos(X,Y)** : This function places the curcer to the X,Y position in the 
        terminal.
- **void setColor(color)** : this function alows the user to change the color of
        text in the terminal.
- **pain createPain(PosX,PosY,sizeX,sizeY,layer)** : This function alows the user to 
        create a box and be able to add data to the box.
- **write(char*)** : this function writes to a slected pain.

### Structures
- **pain** : pain is a text buffer object. In this text buffer it knows its size 
    and its position on the screen. The position starts in the top left corner.
- **master Pain** : the master pain is a holds the main buffer this is where all 
    the draw calls happen.

### Const Settings
- **Colors** : Colors are an object that returns the color from a struct.

