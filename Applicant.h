#ifndef APPLICANT_H
#define APPLICANT_H

#include <string>
using namespace std;

class Applicant {
public:
    int id;
    string name;
    int marks;
    string program;
    string currentProgram;   // NEW for transfer

    Applicant();
};

#endif
