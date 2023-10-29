//
// Created by gribk on 29.10.2023.
//

#include "BinaryTree.h"
#include "../PhoneOwnerCut.h"

#include <utility>

BinaryTree::NodeTree::~NodeTree() {
    delete rightNode;
    delete leftNode;
}

void BinaryTree::NodeTree::print(int level) {
    if (rightNode != nullptr) rightNode->print(level + 1);
    cout << string(level * 10, ' ') << value << " in " << position << endl;
    if (leftNode != nullptr) leftNode->print(level + 1);
}

BinaryTree::NodeTree::NodeTree(string value, int position) : value(std::move(value)), position(position) {
    leftNode = nullptr;
    rightNode = nullptr;
}

bool BinaryTree::NodeTree::operator<(const BinaryTree::NodeTree &rhs) const {
    return PhoneOwnerCut::phoneToLong(value) < PhoneOwnerCut::phoneToLong(rhs.value);
}

bool BinaryTree::NodeTree::operator>(const BinaryTree::NodeTree &rhs) const {
    return rhs < *this;
}

bool BinaryTree::NodeTree::operator<=(const BinaryTree::NodeTree &rhs) const {
    return !(rhs < *this);
}

bool BinaryTree::NodeTree::operator>=(const BinaryTree::NodeTree &rhs) const {
    return !(*this < rhs);
}

bool BinaryTree::NodeTree::operator==(const BinaryTree::NodeTree &rhs) const {
    return PhoneOwnerCut::phoneToLong(value) == PhoneOwnerCut::phoneToLong(rhs.value);
}

bool BinaryTree::NodeTree::operator!=(const BinaryTree::NodeTree &rhs) const {
    return !(rhs == *this);
}

void BinaryTree::print() {
    cout << "Binary tree:" << endl;
    root->print();
}

BinaryTree::BinaryTree() : root(nullptr) {}
