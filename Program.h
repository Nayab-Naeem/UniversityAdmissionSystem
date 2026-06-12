#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
using namespace std;

//Program class represents a university program and manages seat availibility

class Program {
public:
    string name;
    int totalSeats;
    int remainingSeats;       //Remaining seats left for the admission

    Program();
    Program(string n, int seats);
};

#endif
