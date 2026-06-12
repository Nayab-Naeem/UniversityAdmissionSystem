#ifndef ADMITTEDLIST_H
#define ADMITTEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class AdmittedList {
private:
    Node* head;
    int count;

public:
    AdmittedList();
    ~AdmittedList();
    
    void add(Applicant a);
    bool remove(int id);
    void display();
    Node* getHead() { return head; }
    int getCount() { return count; }
    bool isEmpty() { return head == nullptr; }
    Applicant* findById(int id);
};

#endif