//
// Created by gribk on 29.10.2023.
//

#include "BinaryTree.h"

BinaryTree::Node::~Node() {
    delete rightNode;
    delete leftNode;
}

void BinaryTree::Node::print(int level) {
    if (rightNode != nullptr) rightNode->print(level + 1);
    cout << string(level * 10, ' ') << value << endl;
    if (leftNode != nullptr) leftNode->print(level + 1);
}

void BinaryTree::print() {
    cout << "Binary tree:" << endl;
    root->print();
}

BinaryTree::BinaryTree(BinaryTree::Node *root) : root(root) {}
