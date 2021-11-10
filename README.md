# Game of Life 2D Implementation
_Khanh Tran
COMS 327_


**Cellular Automata Project**

Currently the program models a cellular automata where the user can specify: size, rule used, initial states, and the amount of "steps" the CA (cellular automata) goes through.
The program displays a simulation of each cell in the CA processing a specified rule.

_**UPDATED**_

As of November 2021,
The program now supports a 2D array simulation of Conway's Game of Life. The user can input as many "steps" as they choose by pressing enter and the console will display the simulation for each step.

The program has methods for a 1D array as well, but the main program will not simulate this currently.

The code follows these sets of rules for the Game of Life for each simulation: 
- _Any live cell with 2 or 3 neighbors surive._
- _Any dead cell with 3 or more neighbors become a dead cell._
- _Otherwise, cells will die in the next iteration._

**Special Notes**

1: Represents "alive" cells

0: Represents "dead" cells

Neighbors are the numbers around a cell at location (x,y). 
Wrapping logic is included in the code.



