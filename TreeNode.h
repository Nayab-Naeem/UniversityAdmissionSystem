#ifndef TREENODE_H
#define TREENODE_H

#include "Applicant.h"

class TreeNode {
public:
    Applicant data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(Applicant a);
};

#endif
