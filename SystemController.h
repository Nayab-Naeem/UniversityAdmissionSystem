#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include "AdmissionManager.h"
#include <string>

class SystemController {
private:
    AdmissionManager manager;
    int idCounter;

public:
    SystemController();
    void run();
    void displayMenu();
    void handleChoice(int choice);
    
    // Menu handlers
    void applyForAdmission();
    void processApplication();
    void viewAdmittedStudents();
    void viewMeritList();
    void viewRecentProcessed();
    void viewWaitingList();
    void requestTransfer();
};

#endif