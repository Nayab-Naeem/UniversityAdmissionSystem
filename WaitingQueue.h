#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include "Applicant.h"
#include <string>
using namespace std;

struct WaitingNode {
    Applicant applicant;
    WaitingNode* next;
    WaitingNode(Applicant a) : applicant(a), next(nullptr) {}
};

class WaitingQueue {
private:
    WaitingNode* front;
    WaitingNode* rear;
    int count;

public:
    WaitingQueue();
    ~WaitingQueue();
    
    bool isEmpty();
    void enqueue(Applicant a);
    Applicant dequeue();
    Applicant dequeueByProgram(string programName);
    Applicant peek();
    void display();
    int getCount() { return count; }
    int getPosition(int applicantId);
    bool remove(int applicantId);
    void clear();
};

#endif