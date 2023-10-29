//
// Created by gribk on 29.10.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_PHONEOWNERCUT_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_PHONEOWNERCUT_H

#include <string>

using namespace std;

struct PhoneOwnerCut {
    char phone[19];
    char address[56];
    string to_string();

    static unsigned long long int phoneToLong(string phone);

    static string getRandomPhoneNumber(int i);

    static string getRandomAddress(int i);

    static PhoneOwnerCut getRandomOwner(int i);

private:
    static int getRandom(unsigned int i);

public:
    PhoneOwnerCut();

    PhoneOwnerCut(const string& phone, int i);

    PhoneOwnerCut(const string& phone, const string& address);
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_PHONEOWNERCUT_H
