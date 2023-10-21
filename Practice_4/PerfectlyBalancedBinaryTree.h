//
// Created by gribk on 16.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_PERFECTLYBALANCEDBINARYTREE_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_PERFECTLYBALANCEDBINARYTREE_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class PerfectlyBalancedBinaryTree {
private:
    struct Node {
        char value;
        Node *leftNode;
        Node *rightNode;

        Node(int n, vector<char> values);

        virtual ~Node();

        char getBiggestLeaf();
    };

    Node *root;
    int size;

    vector<Node *> getNextLine(const vector<Node *> &line);

    void printLine(vector<Node *> line, int height, int indentation);

    char getMostLeftNode(Node *node);

public:
    PerfectlyBalancedBinaryTree(int count, vector<char> values);

    virtual ~PerfectlyBalancedBinaryTree();

    void print();

    char getMostLeftNode();

    int getPathLengthToNode(char value);

    char getBiggestLeaf();
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_PERFECTLYBALANCEDBINARYTREE_H
