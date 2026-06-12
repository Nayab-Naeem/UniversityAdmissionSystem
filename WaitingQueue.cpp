#include "WaitingQueue.h"
#include <iostream>
#include <iomanip>
using namespace std;

WaitingQueue::WaitingQueue() {
    front = rear = nullptr;
    count = 0;
}

WaitingQueue::~WaitingQueue() {
    clear();
}

bool WaitingQueue::isEmpty() {
    return front == nullptr;
}

void WaitingQueue::enqueue(Applicant a) {
    WaitingNode* newNode = new WaitingNode(a);
    
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

Applicant WaitingQueue::dequeue() {
    Applicant empty;
    if (isEmpty()) {
        return empty;
    }
    
    WaitingNode* temp = front;
    Applicant a = front->applicant;
    front = front->next;
    
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    count--;
    return a;
}

Applicant WaitingQueue::dequeueByProgram(string programName) {
    Applicant empty;
    
    if (isEmpty()) return empty;
    
    // Check if first person wants this program
    if (front->applicant.program == programName) {
        return dequeue();
    }
    
    // Search through the queue
    WaitingNode* current = front;
    while (current->next != nullptr) {
        if (current->next->applicant.program == programName) {
            // Found the person
            WaitingNode* temp = current->next;
            Applicant a = temp->applicant;
            current->next = temp->next;
            
            if (temp == rear) {
                rear = current;
            }
            
            delete temp;
            count--;
            return a;
        }
        current = current->next;
    }
    
    return empty;  // No one found for this program
}

Applicant WaitingQueue::peek() {
    Applicant empty;
    if (isEmpty()) return empty;
    return front->applicant;
}

void WaitingQueue::display() {
    if (isEmpty()) {
        cout << "\n Waiting list is empty.\n";
        return;
    }
    
    cout << "\n" << string(70, '=') << endl;
    cout << "WAITING LIST (Total: " << count << ")" << endl;
    cout << string(70, '=') << endl;
    
    cout << left << setw(5) << "Pos" 
         << setw(10) << "ID" 
         << setw(25) << "Name" 
         << setw(10) << "Marks" 
         << "Program" << endl;
    cout << string(70, '-') << endl;
    
    WaitingNode* current = front;
    int position = 1;
    
    while (current != nullptr) {
        cout << left << setw(5) << position++
             << setw(10) << current->applicant.id
             << setw(25) << current->applicant.name
             << setw(10) << current->applicant.marks
             << current->applicant.program << endl;
        current = current->next;
    }
    cout << string(70, '=') << endl;
}

int WaitingQueue::getPosition(int applicantId) {
    WaitingNode* current = front;
    int position = 1;
    
    while (current != nullptr) {
        if (current->applicant.id == applicantId) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;  // Not found
}

bool WaitingQueue::remove(int applicantId) {
    if (isEmpty()) return false;
    
    // Check if first node
    if (front->applicant.id == applicantId) {
        dequeue();  // Reuse dequeue
        return true;
    }
    
    // Search through the queue
    WaitingNode* current = front;
    while (current->next != nullptr) {
        if (current->next->applicant.id == applicantId) {
            WaitingNode* temp = current->next;
            current->next = temp->next;
            
            if (temp == rear) {
                rear = current;
            }
            
            delete temp;
            count--;
            return true;
        }
        current = current->next;
    }
    
    return false;
}

void WaitingQueue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}