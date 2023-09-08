//
// Created by gribk on 08.09.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_EX2_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_EX2_H


#include <iostream>
#include <iomanip>

using namespace std;

class Ex2 {
    static unsigned char setOneToPosition(unsigned char x, unsigned int position);

    static unsigned int* sortSizeEight(unsigned int* mass, unsigned int size);

    static unsigned int* sortSizeSixtyFour(unsigned int* mass, unsigned int size);

    static void enterMass(unsigned int* mass, unsigned int size);

    static string massToLine(unsigned int *mass, unsigned int size);
public:
    static void start();
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_EX2_H
