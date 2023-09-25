# CLI Tools

CLI tools is a standerd set of tools that allow the user to create a nice TUI with 
basic functions.

## Tools 
These are tools that both windows and linux will have.

### Functions 
- **void setup()** : This function will setup the terminal.
- **void Pos(X,Y)** : This function places the curcer to the X,Y position in the 
        terminal.
- **void SetColor(color)** : this function alows the user to change the color of
        text in the terminal.
- **pain CreateBox(PosX,PosY,sizeX,sizeY)** : This function alows the user to 
        create a box and be able to add data to the box.

### Structures
- **pain** : pain is a text buffer object. In this text buffer it knows its size 
    and its position on the screen. The position starts in the top left corner.

### Const Settings
- **Colors** : Colors are an object that returns the color from a struct.

