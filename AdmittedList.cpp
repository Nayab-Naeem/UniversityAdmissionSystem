#include "AdmittedList.h"
#include <iomanip>

AdmittedList::AdmittedList() {
    head = nullptr;
    count = 0;
}

AdmittedList::~AdmittedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void AdmittedList::add(Applicant a) {
    Node* newNode = new Node;
    newNode->data = a;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count++;
}

bool AdmittedList::remove(int id) {
    if (head == nullptr) return false;
    
    // If head node needs to be removed
    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return true;
    }
    
    // Search for the node to remove
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data.id == id) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            count--;
            return true;
        }
        current = current->next;
    }
    return false;
}

void AdmittedList::display() {
    if (head == nullptr) {
        cout << "\n No admitted students yet.\n";
        return;
    }
    
    cout << "\n" << string(80, '=') << endl;
    cout << "ADMITTED STUDENTS (Total: " << count << ")" << endl;
    cout << string(80, '=') << endl;
    
    cout << left << setw(10) << "ID" 
         << setw(25) << "Name" 
         << setw(10) << "Marks" 
         << "Program" << endl;
    cout << string(80, '-') << endl;
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << left << setw(10) << temp->data.id
             << setw(25) << temp->data.name
             << setw(10) << temp->data.marks
             << temp->data.program << endl;
        temp = temp->next;
    }
    cout << string(80, '=') << endl;
}

Applicant* AdmittedList::findById(int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.id == id) {
            return &temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}