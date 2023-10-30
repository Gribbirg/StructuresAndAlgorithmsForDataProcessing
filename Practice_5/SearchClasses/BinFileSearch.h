//
// Created by gribk on 29.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINFILESEARCH_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINFILESEARCH_H

#include "../BinFileWorkCut.h"
#include "ISearchClass.h"
#include "../PhoneOwnerCut.h"

class BinFileSearch : public BinFileWorkCut {
private:
    ISearchClass *searchObject;

    unsigned int size;

    void dataToSearchObject();
public:

    BinFileSearch(ISearchClass *searchObject, string fileName);

    BinFileSearch(ISearchClass *searchObject, string fileName, int newFileSize);

    bool insert(PhoneOwnerCut phoneOwner) ;

    bool deleteElement(const string &phone);

    PhoneOwnerCut find(const string &phone);
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_BINFILESEARCH_H