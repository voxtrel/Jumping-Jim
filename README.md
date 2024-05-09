# Jumping Jim

Jumping Jim is a C++ program designed to solve maze problems where the objective is to traverse from the top left corner of a matrix to the bottom right corner while obeying specific jump rules associated with each position on the matrix. It sets up the maze problem by creating a directed weighted graph using an adjacency list represntation of the provided matrix, where each vertex corresponds to a position in the matrix and the edges hold the distance of the jumps.

## About the Project

The program utilizes an adjacency list graph representation to create the directed weighted graph for the maze. It solves the problem by traversing through the graph using Depth-First Search (DFS) graph traversal, implemented iteratively using a stack.

### Sample Problem

A sample problem file named `input.txt` is provided with the project. This file contains the dimensions of the matrix on the first line and the matrix itself in the subsequent lines.

- `input.txt` Content:

  `7 7`

  `3 6 4 3 2 4 3`

  `2 1 2 3 2 5 2`

  `2 3 4 3 4 2 3`

  `2 4 4 3 4 2 2`

  `4 5 1 3 2 5 4`

  `4 3 2 2 4 5 6`

  `2 5 2 5 6 1 0`


### Sample Solution

The solution to the provided sample problem is a string with the directions taken to reach the end of the maze. These directions use the cardinal points:
- `E` for east
- `S` for south
- `N` for north
- `W` for west

The solution to the sample problem is:

`E S S N S W E N W E E W S E N W S E`

## Usage

1. Compile the C++ source code.
    
    `g++ JumpingJim.cpp -o jumping_jim`

2. Run the compiled executable from the command line, passing the input file as an argument.

    `./jumping_jim input.txt`

3. The program will output the solution in a file named `output.txt`, which contains the directions taken to traverse the maze.

## Author
Yaniel Gonzalez

## Contributing

Contributions to enhance the program's efficiency or add new features are welcome. Feel free to fork the repository and submit pull requests.

