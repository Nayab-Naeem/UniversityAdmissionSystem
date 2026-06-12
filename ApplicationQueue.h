#ifndef APPLICATIONQUEUE_H
#define APPLICATIONQUEUE_H

#include "Application.h"

class ApplicationQueue {
private:
    Application queue[50];  // Increased size
    int front, rear;

public:
    ApplicationQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(Application a);
    Application dequeue();
    int getCount();
};

#endif