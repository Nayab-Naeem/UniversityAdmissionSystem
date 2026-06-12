#ifndef TRANSFERGRAPH_H
#define TRANSFERGRAPH_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TransferGraph {
private:
    int numPrograms;
    vector<string> programNames;
    vector<vector<int>> adjMatrix;

public:
    TransferGraph(int n);
    void addProgram(string name);
    void addEdge(string from, string to);
    bool canTransfer(string from, string to);
    void displayGraph();
    int getProgramIndex(string name);
    int getNumPrograms() { return numPrograms; }
};

#endif