#ifndef MERITBST_H
#define MERITBST_H

#include "TreeNode.h"
#include <iostream>
#include <string>
using namespace std;

class MeritBST {
private:
    TreeNode* root;
    
    void insert(TreeNode*& node, Applicant a);
    void inOrder(TreeNode* node);
    void inOrderByProgram(TreeNode* node, string programName);
    void clear(TreeNode* node);
    int getCount(TreeNode* node);

public:
    MeritBST();
    ~MeritBST();
    
    void addApplicant(Applicant a);
    void showMeritList();
    void showByProgram(string programName);
    int getTotalCount();
    bool isEmpty() { return root == nullptr; }
};

#endif