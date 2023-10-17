//
// Created by gribk on 16.10.2023.
//

#include "PerfectlyBalancedBinaryTree.h"

#include <utility>

PerfectlyBalancedBinaryTree::PerfectlyBalancedBinaryTree(int count, vector<char> values) {
    size = count;
    if (count != 0)
        root = new Node(count, std::move(values));
    else
        root = nullptr;
}

void PerfectlyBalancedBinaryTree::print() {
    vector<Node *> line;
    line.push_back(root);
    printLine(line, 1, (int) pow(2, (int) log2(size)) * 2 - 1);
}

void PerfectlyBalancedBinaryTree::printLine(vector<Node *> line, int height, int width) {
    if (height - 1 > (int) log2(size)) return;
    int indentation = width / (pow(2, height));
    cout << string(indentation, ' ') << (line[0] == nullptr ? ' ' : line[0]->value);
    indentation *= 2;
    indentation++;
    for (int i = 1; i < line.size(); i++) {
        cout << string(indentation, ' ');
        cout << (line[i] == nullptr ? ' ' : line[i]->value);
    }
    cout << endl;
    printLine(getNextLine(line), height + 1, width);
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

char PerfectlyBalancedBinaryTree::getMostLeftNode(PerfectlyBalancedBinaryTree::Node *node) {
    return (node->leftNode == nullptr) ? node->value : getMostLeftNode(node->leftNode);
}

char PerfectlyBalancedBinaryTree::getMostLeftNode() {
    return getMostLeftNode(root);
}

int PerfectlyBalancedBinaryTree::getPathLengthToNode(char value) {
    vector<Node *> nodes;
    nodes.push_back(root);

    while (!nodes.empty()) {
        for (Node * node : nodes) {
            if (node != nullptr && node->value == value)
                return (int) log2(nodes.size());
        }
        nodes = getNextLine(nodes);
    }

    return -1;
}

char PerfectlyBalancedBinaryTree::getBiggestLeaf() {
    vector<Node *> nodes;
    vector<Node *> nodesPrev;
    vector<Node *> nodesPrevPrev;

    nodes.push_back(root);
    while (!nodes.empty() && !checkForAllNullptr<Node>(nodes)) {
        nodesPrevPrev = nodesPrev;
        nodesPrev = nodes;
        nodes = getNextLine(nodes);
    }
    char maxValue = (char) 0;
    char currentValue;
    for (Node * node: nodesPrevPrev) {

        if (node->leftNode != nullptr && node->rightNode != nullptr)
            currentValue = max(node->leftNode->value, node->rightNode->value);
        else if (node->leftNode != nullptr)
            currentValue = node->leftNode->value;
        else if (node->rightNode != nullptr)
            currentValue =  node->rightNode->value;
        else
            currentValue = node->value;

        maxValue = max(maxValue, currentValue);
    }

    return maxValue;
}

template<typename T>
bool PerfectlyBalancedBinaryTree::checkForAllNullptr(vector<T *> vector) {
    for (T * element : vector)
        if (element != nullptr)
            return false;
    return true;
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
