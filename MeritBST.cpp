#include "MeritBST.h"
#include <iomanip>

MeritBST::MeritBST() {
    root = nullptr;
}

MeritBST::~MeritBST() {
    clear(root);
}

void MeritBST::clear(TreeNode* node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

void MeritBST::insert(TreeNode*& node, Applicant a) {
    if (node == nullptr) {
        node = new TreeNode(a);
        return;
    }
    
    if (a.marks > node->data.marks) {
        insert(node->right, a);  // Higher marks go to right
    } else {
        insert(node->left, a);   // Lower marks go to left
    }
}

void MeritBST::inOrder(TreeNode* node) {
    if (node == nullptr) return;
    
    inOrder(node->right); // Process higher marks first
    cout << left << setw(25) << node->data.name
         << setw(10) << node->data.marks
         << node->data.program << endl;
    inOrder(node->left);
}

void MeritBST::inOrderByProgram(TreeNode* node, string programName) {
    if (node == nullptr) return;
    
    inOrderByProgram(node->right, programName);
    
    if (node->data.program == programName) {
        cout << left << setw(25) << node->data.name
             << setw(10) << node->data.marks
             << node->data.program << endl;
    }
    
    inOrderByProgram(node->left, programName);
}

void MeritBST::addApplicant(Applicant a) {
    insert(root, a);
}

void MeritBST::showMeritList() {
    if (root == nullptr) {
        cout << "\n No applicants in merit list.\n";
        return;
    }
    
    cout << "\n" << string(60, '=') << endl;
    cout << "MERIT LIST (High to Low Marks)" << endl;
    cout << string(60, '=') << endl;
    cout << left << setw(25) << "Name" << setw(10) << "Marks" << "Program" << endl;
    cout << string(60, '-') << endl;
    inOrder(root);
    cout << string(60, '=') << endl;
}

void MeritBST::showByProgram(string programName) {
    cout << "\n" << string(60, '=') << endl;
    cout << "MERIT LIST FOR:" << programName << endl;
    cout << string(60, '=') << endl;
    cout << left << setw(25) << "Name" << setw(10) << "Marks" << "Program" << endl;
    cout << string(60, '-') << endl;
    inOrderByProgram(root, programName);
    cout << string(60, '=') << endl;
}

int MeritBST::getCount(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1 + getCount(node->left) + getCount(node->right);
}

int MeritBST::getTotalCount() {
    return getCount(root);
}
