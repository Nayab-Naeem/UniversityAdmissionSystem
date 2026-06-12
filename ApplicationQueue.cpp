#include "ApplicationQueue.h"

ApplicationQueue::ApplicationQueue()
 {
    front = rear = -1;
}

bool ApplicationQueue::isEmpty() {
    return front == -1;
}

bool ApplicationQueue::isFull() {
    return rear == 49;
}

void ApplicationQueue::enqueue(Application a) {
    if (isFull()) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = a;
}

Application ApplicationQueue::dequeue() {
    Application a;
    if (isEmpty()) return a;
    a = queue[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return a;
}

int ApplicationQueue::getCount() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}