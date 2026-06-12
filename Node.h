#ifndef NODE_H
#define NODE_H

#include "Applicant.h"

class Node {
public:
    Applicant data;
    Node* next;
    Node() : next(nullptr) {}
};

#endif