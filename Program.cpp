#include "Program.h"

Program::Program() {
    name = "";
    totalSeats = 0;
    remainingSeats = 0;
}

Program::Program(string n, int seats) {
    name = n;
    totalSeats = seats;
    remainingSeats = seats;
}