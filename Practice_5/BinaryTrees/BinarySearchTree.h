//
// Created by gribk on 29.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYSEARCHTREE_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYSEARCHTREE_H

#include "BinaryTree.h"
#include "../SearchClasses/ISearchClass.h"

class BinarySearchTree : public BinaryTree, public ISearchClass {
private:

    bool insert(NodeTree *node, const string& phone, int position);

    int deleteElement(NodeTree *node, const string& phone);

    NodeTree *cutMostRightChild(NodeTree *node);

    NodeTree *findNewElement(NodeTree *node);

public:

    bool insert(const string &phone, int position) override;

    int deleteElement(const string &phone) override;

    int find(const string &phone) override;

    void print() override;
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYSEARCHTREE_H
