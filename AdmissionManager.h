#ifndef ADMISSIONMANAGER_H
#define ADMISSIONMANAGER_H

#include "ApplicationQueue.h"
#include "AdmittedList.h"
#include "MeritBST.h"
#include "TransferGraph.h"
#include "Program.h"
#include "WaitingQueue.h"
#include <vector>
#include <string>
using namespace std;

class AdmissionManager {
private:
    ApplicationQueue applications;
    AdmittedList admitted;
    MeritBST meritList;
    TransferGraph transferGraph;
    WaitingQueue waitingList;
    vector<Program> programs;
    
    // For recent applications (circular array)
    Application recentProcessed[10];
    int recentIndex;
    
    // Helper functions
    Program* findProgram(string name);
    void initializePrograms();
    void initializeTransfers();
    void addToRecentProcessed(Application app);
    void admitFromWaitingList(string programName);

public:
    AdmissionManager();
    ~AdmissionManager();
    
    // Application processing
    void submitApplication(Application app);
    void processNextApplication();
    int getPendingApplicationsCount() { return applications.getCount(); }
    
    // Display functions
    void displayPrograms();
    void displayAdmittedStudents();
    void displayMeritList();
    void displayMeritListByProgram(string program);
    void displayRecentProcessed();
    void displayTransferGraph();
    void displayWaitingList();
    
    // Validation
    bool isValidProgram(string program);
    bool hasSeats(string program);
    
    // Transfer functionality
    bool requestTransfer(int studentId, string newProgram);
    
    // Getters
    ApplicationQueue& getApplicationQueue() { return applications; }
    AdmittedList& getAdmittedList() { return admitted; }
    WaitingQueue& getWaitingList() { return waitingList; }
};

#endif