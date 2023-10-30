//
// Created by gribk on 30.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_SPLAYTREE_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_SPLAYTREE_H

#include "BinaryTree.h"
#include "../SearchClasses/ISearchClass.h"
#include "../PhoneOwnerCut.h"

class SplayTree : public BinaryTree, public ISearchClass {
private:
    static NodeTree *leftRotation(NodeTree *node);

    static NodeTree *rightRotation(NodeTree *node);

    static NodeTree *splay(NodeTree *father, unsigned long long int phone);
public:
    bool insert(const string &phone, int position) override;

    int deleteElement(const string &phone) override;

    int find(const string &phone) override;

    void print() override;
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_SPLAYTREE_H
