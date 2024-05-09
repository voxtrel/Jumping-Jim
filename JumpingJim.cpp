#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <unordered_map>

// Yaniel Gonzalez Velez

class Vertex{
    public:
    Vertex(int data){
        jump = data;
        discovered = false;
    }
    int jump;
    int row;
    int col;
    bool discovered;
    std::vector<std::pair<Vertex*, std::string> > adjVertices;  // adjacency list
};

// Build graph
void buildGraph(std::vector<std::vector<Vertex> >& trampolines, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int currJump = trampolines[i][j].jump;
            if(!(i-currJump < 0)){          // if jumping North doesn't go out of bounds then add the vertex in North  
                trampolines[i][j].adjVertices.push_back(std::make_pair(&trampolines[i-currJump][j], "N "));
            }
            if(!(i+currJump > m-1)){        // if jumping South doesn't go out of bounds then add the vertex in South  
                trampolines[i][j].adjVertices.push_back(std::make_pair(&trampolines[i+currJump][j], "S "));
            }
            if(!(j+currJump > n-1)){        // if jumping East doesn't go out of bounds then add the vertex in East  
                trampolines[i][j].adjVertices.push_back(std::make_pair(&trampolines[i][j+currJump], "E "));
            }
            if(!(j-currJump < 0)){          // if jumping West doesn't go out of bounds then add the vertex in West  
                trampolines[i][j].adjVertices.push_back(std::make_pair(&trampolines[i][j-currJump], "W "));
            }
        }
    }
}

void jumpJimTraversal(std::vector<std::vector<Vertex> >& trampolines, int m, int n, std::string& path){
    // traversal
    std::stack<Vertex*> DFS;                                // stack for DFS traversal
    std::unordered_map<Vertex*, std::string> vertexPath;    // map to keep track of path
    vertexPath[&trampolines[0][0]] = "";                    // add starting point to map

    Vertex* curr = &trampolines[0][0];                      // give curr the starting point
    DFS.push(curr);                                         // push curr to the stack
    curr->discovered = true;                                // mark curr as discovered

    // DFS traversal using the stack
    while(!DFS.empty()){
        curr = DFS.top();
        DFS.pop();

        if(curr->row == m-1 && curr->col == n-1){           // This is our goal
            path = vertexPath[curr];                        // get final path
            return;
        }
        
        for(int i=0; i<curr->adjVertices.size(); i++){                                   // go through the neighbors of curr
            if(!curr->adjVertices[i].first->discovered){
                std::string newPath = vertexPath[curr] + curr->adjVertices[i].second;    // append new move
                curr->adjVertices[i].first->discovered = true;                           // make neighbors as dicovered
                DFS.push(curr->adjVertices[i].first);                                    // push undiscovered neighbors to the stack
                vertexPath[curr->adjVertices[i].first] = newPath;                        // update path
            }
        }
    }   
}

int main(){

    int m, n;       // matrix dimensions

    std::ifstream inputFile("input.txt");     // open file 

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << "input.txt" << std::endl;   // if not file not found
        return 1;
    }

    std::string inputs;                 // string to hold input line
    getline(inputFile, inputs);         // get input line

    std::stringstream line1(inputs);    // string stream to extract the inputs
    line1 >> m >> n;                    // extract inputs into m and n

    int temp;
    std::vector<std::vector<Vertex> > trampolines(n, std::vector<Vertex>(m, Vertex(0))); // declare the matrix
    for(int i=0; i<n; i++){                     // for all n
        getline(inputFile, inputs);             // get next line
        std::stringstream data(inputs);         // extract line
        for(int j=0; j<m; j++){                 // for all m
            data >> temp;      
            trampolines[i][j] = Vertex(temp);   // fill the matrix with Vertices
            trampolines[i][j].row = i;          // give the vertex the row
            trampolines[i][j].col = j;          // give the vertex the column
        }
    }

    inputFile.close();  // close input file

    buildGraph(trampolines, m, n);              // function call to build the graph
    std::string path;                           // string to hold the path to goal
    jumpJimTraversal(trampolines, m, n, path);  // function call to tarverse to goal and fill the path

    path.pop_back();    // eliminate space at the end of the string

    // write the path to the output.txt file
    std::ofstream output("output.txt");
    output << path;
    output.close();

    return 0;
}