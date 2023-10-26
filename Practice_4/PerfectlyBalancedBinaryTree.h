//
// Created by gribk on 16.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_PERFECTLYBALANCEDBINARYTREE_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_PERFECTLYBALANCEDBINARYTREE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>


using namespace std;

class PerfectlyBalancedBinaryTree {
private:
    struct Node {
        char value;
        Node *leftNode;
        Node *rightNode;

        Node(vector<char> &values);

        virtual ~Node();

        char getBiggestLeaf();

        char getMostLeftNode();
    };

    Node *root;
    unsigned int size;

    static void outAndUpdateOrder(queue<Node *> &order, const string& out);

public:
    PerfectlyBalancedBinaryTree(vector<char> &values);

    virtual ~PerfectlyBalancedBinaryTree();

    void print();

    char getMostLeftNode();

    int getPathLengthToNode(char value);

    char getBiggestLeaf();
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_PERFECTLYBALANCEDBINARYTREE_H
