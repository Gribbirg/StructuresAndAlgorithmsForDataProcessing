//
// Created by gribk on 29.10.2023.
//

#include "BinarySearchTree.h"

bool BinarySearchTree::insert(const string &phone, int position) {
    if (root == nullptr) {
        root = new NodeTree(phone, position);
        return true;
    }
    return insert(root, new NodeTree(phone, position));
}

int BinarySearchTree::deleteElement(const string &phone) {
    return 0;
}

int BinarySearchTree::find(const string &phone) {
    return 0;
}

void BinarySearchTree::reducePosition(const string &phone) {

}

bool BinarySearchTree::insert(BinaryTree::NodeTree *node, BinaryTree::NodeTree *nodeNew) {
    if (*nodeNew < *node) {
        if (node->leftNode != nullptr)
            return insert(node->leftNode, nodeNew);
        else {
            node->leftNode = nodeNew;
            return true;
        }
    } else if (*nodeNew > *node) {
        if (node->rightNode != nullptr)
            return insert(node->rightNode, nodeNew);
        else {
            node->leftNode = nodeNew;
            return true;
        }
    }
    return false;
}
