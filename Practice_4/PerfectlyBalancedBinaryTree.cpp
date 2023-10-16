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
    if (line.empty()) return;
    int indentation = width / (pow(2, height));
    cout << string(indentation, ' ') << line[0]->value;
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
