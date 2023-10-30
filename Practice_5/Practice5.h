//
// Created by gribk on 29.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_PRACTICE5_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_PRACTICE5_H

#include "SearchClasses/ISearchClass.h"

class Practice5 {
private:
    static void withoutFile(ISearchClass *searchObject);
    static void withFile(ISearchClass *searchObject);
public:
    static void start();
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_PRACTICE5_H
