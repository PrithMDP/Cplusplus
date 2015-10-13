CREDITS:
This project was written by Professor Andrew Deorio at the University of Michigan for EECS 280. Completing and posting this project would not be possible without his help and guidance. 
WEBSITE: http://www.andrewdeorio.com/


WARNING:
The code for this project has been emailed to Prof. Drew Deorio and EECS 280 Staff (at the University of Michigan). Do not attempt to use this code for your project doing so will result in an Honor Code Violation. 

Coded by Prith Yadav 

EECS 280 Project 3: Schelling Segregation Model

Why are neighborhoods often segregated? Thomas Schelling asked this question in his 1969 paper “Models of Segregation.” He was able to show that an individual's slight preference for having neighbors of the same color could lead to total segregation, even when the outcome might not be desired by the entire population. To show how his theory worked, he used a paper grid and moved coins (representing “agents”) to different positions if they were “unsatisfied.”
In this project, you will write a program that simulates the Schelling segregation model. You will gain experience with composable data structures, object­ oriented programming techniques and decomposing a task using functions.

Schelling Model Rules
In our model, we’ll have a grid of agents represented by X’s and O’s. These agents could represent people of different races, religions, socioeconomic classes, etc. Here’s an example of a 5x5 grid with X agents, O agents, and empty spaces.

  X     X  
    X O X 
X O X X O
X O



X O O X X 
X   O O X 
X     O X 
X X X X 
O   O X O


An agent is satisfied if certain percentage of its neighbors are alike. The neighborhood consists of the agent itself, and the 8 surrounding agents, including diagonal. Here are several examples of neighbors, with the center agent in double quotes and the neighbors in single quotes.​

"X" 'O' O              'O' 'O' 'O'          'X' 'O' 'O' X              "O"  'X'               
'X' 'X' O  			   'O' "X" 'X'			'O' "O" 'X' X​​          'O' 'X'  'O'
 O   O  O   		   'X' 'X' 'X'			'X' 'X' 'O' X           O   X    O
 											 X   X   X  O           O   O    X
￼
￼￼￼
For simplicity, we’ll start with agents being satisfied if they are in the majority among their neighbors. Later, we’ll make this configurable (e.g., 1⁄3 of neighbors are alike, etc.) For example, in the following grid, the agent u​nderlined​(upper left 'X') is satisfied because it is in the majority in its neighborhood (shaded). Since this agent is near the corner and some of the neighbors are unoccupied, it has only 1 neighbors (first 'X' in second row), with a total neighborhood size of 2.


  X      X 
    X  O X 
X O X X O

X O

On the other hand, in the following grid (lower left), the agent u​nderlined​is unsatisfied because it is in the minority in its neighborhood (shaded). If an agent is not satisfied, it will move to another location. For simplicity, we’ll move the agent to a randomly selected empty location.
￼
￼
Before move 

  X      X 
    X  O X 
X O X X O

X O
￼
agent located at (2,3) moves to a randomly selected empty location (All indices are relative to 0/ Zero based counting and not 1 based)

After move 

  X      X 
    X  O X 
X   X X O

X O O
￼

The simulation ends when all agents are satisfied, for example:

  X      X 
    X    X 
X   X X  
	 O
X  O  O  O

-------------------------------------------------------------------------

To run on command line type:
g++ -std=c++11 sheclling.cpp -o "your executable here" 
and run with either 

./executable < test.txt
or
./executable test.txt

-------------------------------------------------------------------------
