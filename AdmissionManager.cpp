#include "AdmissionManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
AdmissionManager::AdmissionManager() : transferGraph(5) {  // 5 programs
    recentIndex = 0;
    
    // Initialize all recent processed with empty applications
    for (int i = 0; i < 10; i++) {
        recentProcessed[i].applicant.id = -1;
    }
    
    initializePrograms();
    initializeTransfers();
}

// Destructor
AdmissionManager::~AdmissionManager() {
    // Clean up any dynamically allocated memory if needed
}

// Initialize programs with seats - ALL PROGRAMS HAVE 5 SEATS
void AdmissionManager::initializePrograms() {
    programs.push_back(Program("CS", 5));      // Computer Science - 5 seats
    programs.push_back(Program("IT", 5));      // Information Technology - 5 seats
    programs.push_back(Program("BBA", 5));     // Business Administration - 5 seats
    programs.push_back(Program("LAW", 5));     // Law - 5 seats
    programs.push_back(Program("MEDICINE", 5)); // Medicine - 5 seats
}

// Initialize allowed transfers between programs
void AdmissionManager::initializeTransfers() {
    // Add all program names to graph
    for (int i = 0; i < programs.size(); i++) {
        transferGraph.addProgram(programs[i].name);
    }
    
    // ===== TRANSFER RULES =====
    
    // 1. CS <-> IT (bidirectional)
    transferGraph.addEdge("CS", "IT");
    transferGraph.addEdge("IT", "CS");
    
    // 2. CS -> BBA
    transferGraph.addEdge("CS", "BBA");
    
    // 3. CS -> LAW
    transferGraph.addEdge("CS", "LAW");
    
    // 4. MEDICINE -> LAW
    transferGraph.addEdge("MEDICINE", "LAW");
    
    // 5. MEDICINE -> BBA
    transferGraph.addEdge("MEDICINE", "BBA");
    
    // Note: No other transfers are allowed
    // - BBA cannot transfer to anyone
    // - LAW cannot transfer to anyone
    // - IT can only transfer to CS (already added above)
    // - No transfers into MEDICINE
}

// Find program by name
Program* AdmissionManager::findProgram(string name) {
    for (int i = 0; i < programs.size(); i++) {
        if (programs[i].name == name) {
            return &programs[i];
        }
    }
    return nullptr;
}

// Add to circular buffer of recent processed
void AdmissionManager::addToRecentProcessed(Application app) {
    recentProcessed[recentIndex] = app;
    recentIndex = (recentIndex + 1) % 10;
}

// Admit first person from waiting list for a specific program
void AdmissionManager::admitFromWaitingList(string programName) {
    Applicant applicant = waitingList.dequeueByProgram(programName);
    
    if (applicant.id != -1) {
        // Create application from applicant
        Application app;
        app.applicant = applicant;
        
        // Admit them
        admitted.add(applicant);
        meritList.addApplicant(applicant);
        addToRecentProcessed(app);
        
        cout << "\nADMITTED FROM WAITING LIST!" << endl;
        cout << "   " << applicant.name << " to " << programName << endl;
    }
}

// Submit new application
void AdmissionManager::submitApplication(Application app) {
    applications.enqueue(app);
    cout << "\nApplication submitted successfully!" << endl;
    cout << "Name: " << app.applicant.name << endl;
    cout << "Program: " << app.applicant.program << endl;
    cout << "Pending applications: " << applications.getCount() << endl;
}

// Process the next application in queue
void AdmissionManager::processNextApplication() {
    if (applications.isEmpty()) {
        cout << "\nNo applications to process!" << endl;
        return;
    }
    
    Application app = applications.dequeue();
    Program* prog = findProgram(app.applicant.program);
    
    if (!prog) {
        cout << "\nError: Program not found!" << endl;
        return;
    }
    
    cout << "\n" << string(50, '=') << endl;
    cout << "PROCESSING APPLICATION" << endl;
    cout << string(50, '=') << endl;
    cout << "ID: " << app.applicant.id << endl;
    cout << "Name: " << app.applicant.name << endl;
    cout << "Program: " << app.applicant.program << endl;
    cout << "Marks: " << app.applicant.marks << endl;
    cout << string(50, '-') << endl;
    
    // Check if program has seats (all programs have 5 seats)
    if (prog->remainingSeats > 0) {
        // Admit the student
        admitted.add(app.applicant);
        meritList.addApplicant(app.applicant);
        prog->remainingSeats--;
        addToRecentProcessed(app);
        
        cout << "RESULT: ADMITTED" << endl;
        cout << "Remaining seats in " << prog->name << ": " 
             << prog->remainingSeats << "/" << prog->totalSeats << endl;
    } else {
        // Add to waiting list
        waitingList.enqueue(app.applicant);
        addToRecentProcessed(app);
        
        cout << "RESULT: WAITING LIST" << endl;
        cout << "Program is full. Added to waiting list." << endl;
        cout << "Position in waiting list: " << waitingList.getCount() << endl;
    }
    cout << string(50, '=') << endl;
}

// Display all programs and available seats
void AdmissionManager::displayPrograms() {
    cout << "\n" << string(60, '=') << endl;
    cout << " AVAILABLE PROGRAMS (All have 5 seats)" << endl;
    cout << string(60, '=') << endl;
    
    cout << left << setw(15) << "Program" 
         << setw(15) << "Total Seats" 
         << setw(15) << "Available" 
         << "Status" << endl;
    cout << string(60, '-') << endl;
    
    for (int i = 0; i < programs.size(); i++) {
        string status = (programs[i].remainingSeats > 0) ? "Open" : "Full";
        cout << left << setw(15) << programs[i].name
             << setw(15) << programs[i].totalSeats
             << setw(15) << programs[i].remainingSeats
             << status << endl;
    }
    cout << string(60, '=') << endl;
}

// Display all admitted students
void AdmissionManager::displayAdmittedStudents() {
    admitted.display();
}

// Display complete merit list
void AdmissionManager::displayMeritList() {
    meritList.showMeritList();
}

// Display merit list for specific program
void AdmissionManager::displayMeritListByProgram(string program) {
    if (!isValidProgram(program)) {
        cout << "\nInvalid program name!" << endl;
        cout << "Valid programs: CS, IT, BBA, LAW, MEDICINE" << endl;
        return;
    }
    meritList.showByProgram(program);
}

// Display recently processed applications
void AdmissionManager::displayRecentProcessed() {
    cout << "\n" << string(70, '=') << endl;
    cout << " RECENTLY PROCESSED APPLICATIONS (Last 10)" << endl;
    cout << string(70, '=') << endl;
    
    bool found = false;
    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(15) << "Program" 
         << setw(10) << "Marks" << "Result" << endl;
    cout << string(70, '-') << endl;
    
    for (int i = 0; i < 10; i++) {
        int index = (recentIndex - 1 - i + 10) % 10;
        if (recentProcessed[index].applicant.id != -1) {
            found = true;
            
            // Determine result based on whether program had seats at time of processing
            string result = "Processed";
            
            cout << left << setw(10) << recentProcessed[index].applicant.id
                 << setw(20) << recentProcessed[index].applicant.name
                 << setw(15) << recentProcessed[index].applicant.program
                 << setw(10) << recentProcessed[index].applicant.marks
                 << result << endl;
        }
    }
    
    if (!found) {
        cout << "No applications processed yet." << endl;
    }
    cout << string(70, '=') << endl;
}

// Display transfer graph
void AdmissionManager::displayTransferGraph() {
    transferGraph.displayGraph();
}

// Display waiting list
void AdmissionManager::displayWaitingList() {
    waitingList.display();
}

// Check if program name is valid
bool AdmissionManager::isValidProgram(string program) {
    return findProgram(program) != nullptr;
}

// Check if program has available seats
bool AdmissionManager::hasSeats(string program) {
    Program* prog = findProgram(program);
    return (prog && prog->remainingSeats > 0);
}

// Process transfer request
bool AdmissionManager::requestTransfer(int studentId, string newProgram) {
    // Find student in admitted list
    Applicant* student = admitted.findById(studentId);
    
    if (!student) {
        cout << "\nStudent not found in admitted list!" << endl;
        return false;
    }
    
    cout << "\n" << string(60, '=') << endl;
    cout << "PROCESSING TRANSFER REQUEST"<<endl;
    cout << string(60, '=') << endl;
    cout << "Student: " << student->name << " (ID: " << student->id << ")" << endl;
    cout << "From: " << student->program << "To: " << newProgram << endl;
    cout << string(60, '-') << endl;
    
    // Check if new program exists
    Program* newProg = findProgram(newProgram);
    if (!newProg) {
        cout << "Error: Program '" << newProgram << "not found!" << endl;
        cout << "Valid programs: CS, IT, BBA, LAW, MEDICINE" << endl;
        return false;
    }
    
    // Check if transfer is allowed
    if (!transferGraph.canTransfer(student->program, newProgram)) {
        cout << "Transfer not allowed! No direct transfer path." << endl;
        cout << "ALLOWED TRANSFERS:" << endl;
        cout << "CS ↔ IT" << endl;
        cout << "CS → BBA"<< endl;
        cout << "CS → LAW" << endl;
        cout << "MEDICINE → LAW" << endl;
        cout << "MEDICINE → BBA" << endl;
        return false;
    }
    
    // Check if new program has seats
    if (newProg->remainingSeats <= 0) {
        cout << "No seats available in " << newProgram << endl;
        return false;
    }
    
    // Find old program
    Program* oldProg = findProgram(student->program);
    if (!oldProg) {
        cout << "Error: Original program not found!" << endl;
        return false;
    }
    
    // Process the transfer
    oldProg->remainingSeats++;  // Free up seat in old program
    newProg->remainingSeats--;  // Occupy seat in new program
    
    // Update student's program
    string oldProgram = student->program;
    student->program = newProgram;
    
    cout << "TRANSFER SUCCESSFUL!" << endl;
    cout << "Seat freed in " << oldProgram << ": " 
         << oldProg->remainingSeats << "/5 available" << endl;
    cout << "Seat taken in " << newProgram << ": " 
         << newProg->remainingSeats << "/5 remaining" << endl;
    cout << string(60, '=') << endl;
    
    // Check if anyone is waiting for the old program
    if (!waitingList.isEmpty()) {
        admitFromWaitingList(oldProgram);
    }
    
    return true;
}