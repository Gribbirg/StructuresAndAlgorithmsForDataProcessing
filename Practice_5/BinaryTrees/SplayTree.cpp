//
// Created by gribk on 30.10.2023.
//

#include "SplayTree.h"

bool SplayTree::insert(const string &phone, int position) {

    if (root == nullptr) {
        root = new NodeTree(phone, position);
        return true;
    }

    unsigned long long int phoneNum = PhoneOwnerCut::phoneToLong(phone);

    root = splay(root, phoneNum);

    if (root->value == phone)
        return false;

    auto node = new NodeTree(phone, position);

    if (phoneNum < PhoneOwnerCut::phoneToLong(root->value)) {
        node->rightNode = root;
        node->leftNode = root->leftNode;
        root->leftNode = nullptr;
    } else {
        node->leftNode = root;
        node->rightNode = root->rightNode;
        root->rightNode = nullptr;
    }
    root = node;
    return true;
}

int SplayTree::deleteElement(const string &phone) {
    int position = find(phone);
    if (position != -1) {
        if (root->leftNode == nullptr) {
            root = root->rightNode;
        } else {
            NodeTree *node = root->rightNode;
            root = root->leftNode;
            root = splay(root, PhoneOwnerCut::phoneToLong(phone));
            root->rightNode = node;
        }
        root->reducePositions(position);
    }
    return position;
}

int SplayTree::find(const string &phone) {
    if (root == nullptr) return -1;

    root = splay(root, PhoneOwnerCut::phoneToLong(phone));

    return (root->value == phone) ? root->position : -1;
}

void SplayTree::print() {
    BinaryTree::print();
}

BinaryTree::NodeTree *SplayTree::leftRotation(BinaryTree::NodeTree *node) {
    NodeTree *child = node->rightNode;
    node->rightNode = child->leftNode;
    child->leftNode = node;
    return child;
}

BinaryTree::NodeTree *SplayTree::rightRotation(BinaryTree::NodeTree *node) {
    NodeTree *child = node->leftNode;
    node->leftNode = child->rightNode;
    child->rightNode = node;
    return child;
}

BinaryTree::NodeTree *SplayTree::splay(NodeTree *father, unsigned long long int phone) {
    if (father == nullptr || phone == PhoneOwnerCut::phoneToLong(father->value)) return father;

    if (phone < PhoneOwnerCut::phoneToLong(father->value)) {

        if (father->leftNode == nullptr) return father;

        if (phone < PhoneOwnerCut::phoneToLong(father->leftNode->value)) {

            father->leftNode->leftNode = splay(father->leftNode->leftNode, phone);
            father = rightRotation(father);

        } else if (phone > PhoneOwnerCut::phoneToLong(father->leftNode->value)) {

            father->leftNode->rightNode = splay(father->leftNode->rightNode, phone);
            if (father->leftNode->rightNode != nullptr)
                father->leftNode = leftRotation(father->leftNode);

        }

        return (father->leftNode == nullptr) ? father : rightRotation(father);

    } else {

        if (father->rightNode == nullptr) return father;

        if (phone < PhoneOwnerCut::phoneToLong(father->rightNode->value)) {

            father->rightNode->leftNode = splay(father->rightNode->leftNode, phone);
            if (father->rightNode->leftNode != nullptr)
                father->rightNode = rightRotation(father->rightNode);

        } else if (phone > PhoneOwnerCut::phoneToLong(father->rightNode->value)) {

            father->rightNode->rightNode = splay(father->rightNode->rightNode, phone);
            father = leftRotation(father);

        }

        return (father->rightNode == nullptr) ? father : leftRotation(father);

    }
}

SplayTree::~SplayTree() {
    delete root;
}
