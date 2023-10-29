//
// Created by gribk on 29.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYSEARCHTREE_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYSEARCHTREE_H

#include "BinaryTree.h"
#include "../SearchClasses/ISearchClass.h"

class BinarySearchTree : public BinaryTree, public ISearchClass {
private:

    bool insert(NodeTree *node, NodeTree *nodeNew);

public:

    bool insert(const string &phone, int position) override;

    int deleteElement(const string &phone) override;

    int find(const string &phone) override;

    void reducePosition(const string &phone) override;

};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINARYSEARCHTREE_H
