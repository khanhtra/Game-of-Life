**CONWAY'S GAME OF LIFE IN C++**


The program currently displays a screen with a cellular automaton model on it. Pressing enter in the console window will simulate one step of Conway's Game of Life. Alive states are represented by a solid square and dead states are represented by a hollow square, the display's default color is black but a user can change it to any RGB color that is desired. Pressing a character followed by enter will stop the connection to the display and terminate the program.

_Graphics Client (GraphicsClient.cpp and GraphicsClient.h)_

    Allows the user to interact with a graphics server, supplied by my professor. Features of the graphics client include: 

    1. Setting background color
    2. Set drawing color
    3. Draw/fill rectangles 
    4. Draw/fill ovals
    5. Set a pixel at a location
    6. Draw a line
    7. Write a string 
    8. Create a "file browser" for the user to select specific text files.
    
    The code is written in a way that interacts with the graphics server through formats given by the instructor, 
    a series of "messages" are used and sent to the graphics server using c sockets. Each feature is accessed by using 
    a code recognized by the server and the specific details of how the feature should display is chosen by the programmer.
    For example, the programmer specifies length(5), width(4), position(1,2) and then uses a code to send to the server, a 
    rectangle will be created at location (1,2) and will have dimensions of length(5) and width(4).

_Cellular Automaton Model (CellularAutomaton.cpp and CellularAutomaton.h)_

    Creates a model of a 2-D cellular automaton object that is used in conjunction with the graphics client and server. The 
    program is structured so a user can specify a grid in the format: Rows, Columns, Grid layout in a text file. The program will
    create a model of a cellular automaton given these parameters. There is a function called "step" which will model a simulation 
    of one step of a certain rule on the cellular automaton model, as of now, only Conway's Game of Life is included with the program.
    The last function that is included is a "display" function which will display the current state of a cellular automaton model to
    the graphics server provided. The "display" function works in tandem with GraphicsClient.cpp. For the present implementation, 
    "alive" states are modeled by a solid square, and "dead" states are modeled by a hollow square. Cell size and cell gap are hard 
    coded. 

_CA Simulator (GraphicsClient.cpp,GraphicsClient.h, and casimulator.cpp)_
    Creates a pre-determined GUI layout that I have designed. The GUI displays buttons that respond to clicks given by the Graphics 
    Server and perform actions based on what is "clicked". I have designed the GUI so that whenever a click is performed the button 
    will flash a color to indicate it is being pressed, with the exception of "RUN", where the button will remain green until "PAUSE" 
    is clicked.

        



**CONWAY'S GAME OF LIFE IN C**



The code follows these sets of rules for the Game of Life for each simulation: 
- _Any live cell with 2 or 3 neighbors surive._
- _Any dead cell with 3 or more neighbors become a dead cell._
- _Otherwise, cells will die in the next iteration._

Neighbors are the numbers around a cell at location (x,y) in the array presented in the console. 

Wrapping logic is included in the code.

**How to simulate a pattern from the Game of Life** : 

Set specific locations according to the desired pattern, the program will output a 2D array displaying the current state after x amount of times.


