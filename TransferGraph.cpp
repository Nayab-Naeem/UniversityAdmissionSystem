#include "TransferGraph.h"
#include <iomanip>

TransferGraph::TransferGraph(int n) {
    numPrograms = n;
    adjMatrix.resize(n, vector<int>(n, 0));
}

void TransferGraph::addProgram(string name) {
    if (programNames.size() < numPrograms) {
        programNames.push_back(name);
    }
}

int TransferGraph::getProgramIndex(string name) {
    for (int i = 0; i < programNames.size(); i++) {
        if (programNames[i] == name) return i;
    }
    return -1;
}

void TransferGraph::addEdge(string from, string to) {
    int u = getProgramIndex(from);
    int v = getProgramIndex(to);
    if (u != -1 && v != -1) {
        adjMatrix[u][v] = 1;
    }
}

bool TransferGraph::canTransfer(string from, string to) {
    int u = getProgramIndex(from);
    int v = getProgramIndex(to);
    if (u == -1 || v == -1) return false;
    return adjMatrix[u][v] == 1;
}

void TransferGraph::displayGraph() {
    cout << "\n" << string(50, '=') << endl;
    cout << "ALLOWED PROGRAM TRANSFERS" << endl;
    cout << string(50, '=') << endl;
    
    for (int i = 0; i < programNames.size(); i++) {
        cout << left << setw(20) << programNames[i] << " to ";
        bool hasEdges = false;
        
        for (int j = 0; j < programNames.size(); j++) {
            if (adjMatrix[i][j]) {
                cout << programNames[j] << "  ";
                hasEdges = true;
            }
        }
        
        if (!hasEdges) {
            cout << "No transfers allowed";
        }
        cout << endl;
    }
    cout << string(50, '=') << endl;
}