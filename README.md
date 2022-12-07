# Game of Life 2D Implementation C and C++
_Khanh Tran
COMS 327_


**Cellular Automata Simulator**

Currently the program creates a GUI of a model of an cellular automata where the user can click on "buttons" that perform the following: 

1. Iterate once (STEP)
2. Iterate indefinitely (RUN)
3. Pause the simulation (PAUSE)
4. Reset to loaded file model (RESET)
5. Randomize each cell (0 or 1) of current model (RANDOM)
6. Load desired text file (LOAD)
7. Clear the screen (CLEAR)
8. Select one of three model sizes (SELECT SIZE -- click on 1,2, or 3)
9. End the simulation (QUIT)


The program will update according to the corresponding button clicks. The user can toggle any cell by clicking on the square and it will either change from dead to alive (blank square to outlined square) or vice versa.

The cells are displayed on a graphics server (**GraphicsServerV2.jar**) along with a created GUI.

_**The CA simulation screen (left side) when first running the program is left intentionally blank so the user can click on cells to make it become "alive". The initial space where the user can click is 240x240 pixels.**_

**How to run on a Linux machine**


1. Open two terminal windows and use command "cd" to locate files


2. Use command "java -jar GraphicsServerv2.jar" in one window, the user should see "Listening on port 7777" on the console

3. Use command "make" in the other terminal window

4. An executable file "**gol.exe**" should be present in the location you've used "cd" on

5. To run the "**CASimulator.exe**" use command "./CASimulator" in the console

6. A display should pop up in a separate window

7. Click on given buttons to simulate your desired action

8. Re-run program by using step 5.











