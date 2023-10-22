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
    queue<Node *> order;
    order.push(root);
    int height = 0;
    int indentation = ((int) pow(2, (int) log2(size)) * 2 - 1);
    while (height - 1 < (int) log2(size)) {
        cout << string((indentation - 1) / 2, ' ');
        for (int i = 0; i < pow(2, height) - 1; i++)
            outAndUpdateOrder(order, string(indentation, ' '));
        outAndUpdateOrder(order, string((indentation - 1) / 2, ' '));
        cout << endl;
        height++;
        indentation /= 2;
    }
}

void PerfectlyBalancedBinaryTree::outAndUpdateOrder(queue<Node *> &order, const string& out) {
    if (order.front() == nullptr)
        cout << ' ';
    else {
        cout << order.front()->value;
        order.push(order.front()->leftNode);
        order.push(order.front()->rightNode);
    }
    order.pop();
    cout << out;
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
    queue<Node *> nodes;
    Node *node;
    nodes.push(root);
    int len = 1;
    int height = 0;

    while (len != 0) {
        for (int i = 0; i < len; i++) {
            node = nodes.front();
            nodes.pop();
            if (node->value == value)
                return height;
            if (node-> leftNode != nullptr) nodes.push(node->leftNode);
            if (node-> rightNode != nullptr) nodes.push(node->rightNode);
        }
        len = nodes.size();
        height++;
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

