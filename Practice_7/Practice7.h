//
// Created by gribk on 27.11.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_PRACTICE7_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_PRACTICE7_H

#include "string"
#include "iostream"
#include "fstream"

using namespace std;

class Practice7 {
private:
    unsigned int bruteForceMethod(const string& text);
    bool check(const string& text);
    unsigned long long int counter;
    explicit Practice7(unsigned long long int counter);
public:
    static void start();
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_PRACTICE7_H
