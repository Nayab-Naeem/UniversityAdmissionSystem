#include "SystemController.h"
#include "ConsoleColor.h"
#include <iostream>
#include <limits>
using namespace std;

//function for centre print output
void printCentered(string text, int width = 80) {
    int padding = (width - text.length()) / 2;
    if (padding > 0)
        cout << string(padding, ' ');
    cout << text << endl;
}



SystemController::SystemController() {
    idCounter = 1;
}

void SystemController::displayMenu()
 {
   setColor(14); // yellow

cout << endl;  // keeps the top spacing

printCentered(string(50, '='));
printCentered("UNIVERSITY ADMISSION SYSTEM");
printCentered(string(50, '='));

setColor(7);   // reset
    
    setColor(11); // Cyan
    cout << "1. Apply for Admission" << endl;
    cout << "2. Process Next Application" << endl;
    cout << "3. View Admitted Students" << endl;
    cout << "4. View Merit List by Program" << endl;
    cout << "5. View Recently Processed" << endl;
    cout << "6. View Waiting List" << endl;
    cout << "7. Department Transfer Request" << endl;
    cout << "8. View All Programs" << endl;
    cout << "9. Exit" << endl;
    cout << string(50, '-') << endl;
    cout << "Pending Applications: " << manager.getPendingApplicationsCount() << endl;
    cout << string(50, '-') << endl;
    
    setColor(7); // White
    cout << "Enter choice (1-9): ";
}

void SystemController::applyForAdmission() {
    Application app;
    app.applicant.id = idCounter++;
    
    // Name validation
    do {
        cout << "Enter Name: ";
        getline(cin, app.applicant.name);
        if (app.applicant.name.empty()) {
            setColor(12); // Red
            cout << "ERROR: Name cannot be empty!\n";
            setColor(7);
        }
    } while (app.applicant.name.empty());
    
    // Marks validation
    while (true) {
        cout << "Enter Marks (0 - 100): ";
        cin >> app.applicant.marks;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            setColor(12);
            cout << "ERROR: Invalid input! Enter numbers only.\n";
            setColor(7);
            continue;
        }
        
        if (app.applicant.marks < 0 || app.applicant.marks > 100) {
            setColor(12);
            cout << "ERROR: Marks must be between 0 and 100.\n";
            setColor(7);
            continue;
        }
        break;
    }
    cin.ignore();
    
    // Program validation
    manager.displayPrograms();
    bool validProgram = false;
    do {
        cout << "Enter Program Name exactly as shown: ";
        getline(cin, app.applicant.program);
        validProgram = manager.isValidProgram(app.applicant.program);
        if (!validProgram) {
            setColor(12);
            cout << "ERROR: Invalid program name! Try again.\n";
            setColor(7);
        }
    } while (!validProgram);
    
    manager.submitApplication(app);
    
    setColor(10); // Green
    cout << "\nApplication Submitted Successfully!" << endl;
    cout << "Your Applicant ID: " << app.applicant.id << endl;
    setColor(7);
}

void SystemController::processApplication() {
    manager.processNextApplication();
}

void SystemController::viewAdmittedStudents() {
    manager.displayAdmittedStudents();
}

void SystemController::viewMeritList() {
    string program;
    cout << "Enter program name: ";
    getline(cin, program);
    manager.displayMeritListByProgram(program);
}

void SystemController::viewRecentProcessed() {
    manager.displayRecentProcessed();
}

void SystemController::viewWaitingList() {
    manager.displayWaitingList();
}

void SystemController::requestTransfer() {
    int id;
    string newProgram;
    
    cout << "Enter your Applicant ID: ";
    cin >> id;
    cin.ignore();
    
    manager.displayTransferGraph();
    cout << "Enter new program to transfer: ";
    getline(cin, newProgram);
    
    if (manager.requestTransfer(id, newProgram)) {
        setColor(10);
        cout << "\nTransfer successful!" << endl;
        setColor(7);
    } else {
        setColor(12);
        cout << "\nTransfer failed!" << endl;
        setColor(7);
    }
}

void SystemController::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: applyForAdmission(); break;
            case 2: processApplication(); break;
            case 3: viewAdmittedStudents(); break;
            case 4: viewMeritList(); break;
            case 5: viewRecentProcessed(); break;
            case 6: viewWaitingList(); break;
            case 7: requestTransfer(); break;
            case 8: manager.displayPrograms(); break;
            case 9: 
                setColor(14); // Yellow
                cout << "\nThank you for using the University Admission System!\n";
                setColor(7);
                break;
            default:
                setColor(12);
                cout << "\nERROR: Invalid choice! Please enter 1-9.\n";
                setColor(7);
        }
    } while (choice != 9);
}