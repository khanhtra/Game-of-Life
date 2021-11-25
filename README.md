# Game of Life 2D Implementation C and C++
_Khanh Tran
COMS 327_


**Cellular Automata Project**

Currently the program models a cellular automata where the user can specify: size, rule used, initial states, and the amount of "steps" the CA (cellular automata) goes through. 
The program displays a simulation of each cell in the CA processing a specified rule.
The cells are displayed on a graphics server (**GraphicsServer.jar**) that is provided and a graphics client (**GraphicsClient.cpp**) is used to connect and send specific commands to. 

**How to run on a Linux machine**


1. Open two terminal windows and use command "cd" to locate files


2. Use command "java -jar GraphicsServer.jar 7777" in one window, the user should see "Listening on port 7777" on the console

3. User command "make" in the other terminal window

4. An executable file "**gol.exe**" should be present in the location you've used "cd" on

5. To run the "**gol.exe**" use command "./gol "file name", where file name is the name of the text file you wish to run the program with

    _Note: Text files should be of format: rows, cols, array[rows][cols] in that order, see "blinker.txt" in the repo for an example._

6. A display should pop up in a separate window and display a representation of a grid specified in the text file in step 5.

7. Pressing enter on the same window as step 5 will simulate one step of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), keep pressing enter to simulate more steps.

8. To disconnect the program and display, press any character followed by enter.

9. Go through steps 2-5 to rerun the program.











