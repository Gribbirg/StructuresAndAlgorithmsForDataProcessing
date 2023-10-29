//
// Created by gribk on 29.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYTREE_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYTREE_H

#include <string>
#include <iostream>

using namespace std;

class BinaryTree {
protected:
    struct Node {
        string value;
        Node *leftNode;
        Node *rightNode;

        ~Node();

        void print(int level = 0);
    };

    Node *root;
    BinaryTree(Node *root);

public:

    void print();
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYTREE_H
