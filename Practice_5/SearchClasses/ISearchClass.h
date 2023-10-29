//
// Created by gribk on 29.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_ISEARCHCLASS_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_ISEARCHCLASS_H

#include <string>

using namespace std;

class ISearchClass {
public:
    virtual bool insert(const string &phone, int position) = 0;
    virtual int deleteElement(const string &phone) = 0;
    virtual int find(const string &phone) = 0;
    virtual void reducePosition(const string &phone) = 0;
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_ISEARCHCLASS_H
