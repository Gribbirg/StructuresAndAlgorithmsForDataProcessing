//
// Created by gribk on 16.10.2023.
//

#include "PerfectlyBalancedBinaryTree.h"

#include <utility>
#include <queue>

PerfectlyBalancedBinaryTree::PerfectlyBalancedBinaryTree(int count, vector<char> values) {
    size = count;
    if (count != 0)
        root = new Node(count, std::move(values));
    else
        root = nullptr;
}

void PerfectlyBalancedBinaryTree::print() {
    queue<Node *> order;
    order.push(root);
    int height = 0;
    int indentation = ((int) pow(2, (int) log2(size)) * 2 - 1);
    while (height - 1 < (int) log2(size)) {
        cout << string((indentation - 1) / 2, ' ');
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (order.front() == nullptr)
                cout << ' ';
            else {
                cout << order.front()->value;
                order.push(order.front()->leftNode);
                order.push(order.front()->rightNode);
            }
            order.pop();
            cout << string(indentation, ' ');
        }
        if (order.front() == nullptr)
            cout << ' ';
        else {
            cout << order.front()->value;
            order.push(order.front()->leftNode);
            order.push(order.front()->rightNode);
        }
        order.pop();
        cout << string((indentation - 1) / 2, ' ') << endl;
        height++;
        indentation /= 2;
    }
}

vector<PerfectlyBalancedBinaryTree::Node *> PerfectlyBalancedBinaryTree::getNextLine(const vector<Node *> &line) {
    vector<Node *> newLine;
    for (Node *node: line) {
        if (node == nullptr) {
            newLine.clear();
            break;
        }
        newLine.push_back(node->leftNode);
        newLine.push_back(node->rightNode);
    }
    return newLine;
}

PerfectlyBalancedBinaryTree::~PerfectlyBalancedBinaryTree() {
    delete root;
}

char PerfectlyBalancedBinaryTree::Node::getMostLeftNode() {
    return (leftNode == nullptr) ? value : leftNode->getMostLeftNode();
}

char PerfectlyBalancedBinaryTree::getMostLeftNode() {
    return root->getMostLeftNode();
}

int PerfectlyBalancedBinaryTree::getPathLengthToNode(char value) {
    vector<Node *> nodes;
    nodes.push_back(root);

    while (!nodes.empty()) {
        for (Node *node: nodes) {
            if (node != nullptr && node->value == value)
                return (int) log2(nodes.size());
        }
        nodes = getNextLine(nodes);
    }

    return -1;
}

char PerfectlyBalancedBinaryTree::getBiggestLeaf() {
    return root->getBiggestLeaf();
}

char PerfectlyBalancedBinaryTree::Node::getBiggestLeaf() {
    if (leftNode == nullptr && rightNode == nullptr)
        return value;
    if (leftNode == nullptr)
        return rightNode->getBiggestLeaf();
    if (rightNode == nullptr)
        return leftNode->getBiggestLeaf();
    return max(leftNode->getBiggestLeaf(), rightNode->getBiggestLeaf());
}

PerfectlyBalancedBinaryTree::Node::Node(int n, vector<char> values) {

    this->value = values[0];
    int nl = n / 2;
    int nr = n - nl - 1;
    vector<char> valLeft;
    vector<char> valRight;

    if (nl != 0)
        leftNode = new Node(nl, vector<char>(values.begin() + 1, values.begin() + 1 + nl));
    else
        leftNode = nullptr;
    if (nr != 0)
        rightNode = new Node(nr, vector<char>(values.begin() + 1 + nl, values.end()));
    else
        rightNode = nullptr;
}

PerfectlyBalancedBinaryTree::Node::~Node() {
    delete leftNode;
    delete rightNode;
}

