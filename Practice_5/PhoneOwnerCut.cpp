//
// Created by gribk on 29.10.2023.
//

#include "PhoneOwnerCut.h"
#include <ctime>
#include <random>
#include <cstring>

PhoneOwnerCut::PhoneOwnerCut() {}

PhoneOwnerCut::PhoneOwnerCut(const string &phone, int i) {
    strcpy(this->phone, phone.c_str());
    strcpy(this->address, PhoneOwnerCut::getRandomAddress(i).c_str());
}

PhoneOwnerCut::PhoneOwnerCut(const string &phone, const string &address) {
    strcpy(this->phone, phone.c_str());
    strcpy(this->address, address.c_str());
}

PhoneOwnerCut PhoneOwnerCut::getRandomOwner(int i) {
    return {getRandomPhoneNumber(i), getRandomAddress(i)};
}

string PhoneOwnerCut::to_string() {
    return "Phone owner: phone - " + string(phone) + "; address - " + string(address) + ".";
}

unsigned long long int PhoneOwnerCut::phoneToLong(string phone) {
    return stoll(string({
                                phone[4],
                                phone[5],
                                phone[6],
                                phone[9],
                                phone[10],
                                phone[11],
                                phone[13],
                                phone[14],
                                phone[16],
                                phone[17]
                        }));
}

int PhoneOwnerCut::getRandom(unsigned int i) {
    srand((unsigned) (time(nullptr) + i));
    return rand();
}

string PhoneOwnerCut::getRandomPhoneNumber(int i) {
    string ans;
    int rand = getRandom(i << 0);
    ans += "+7 (" + std::to_string(rand % 10) + std::to_string(rand % 100 / 10) + std::to_string(rand % 1000 / 100) +
           ") ";
    rand = getRandom(i << 1);
    ans += std::to_string(rand % 10) + std::to_string(rand % 100 / 10) + std::to_string(rand % 1000 / 100) + "-";
    rand = getRandom(i << 2);
    ans += std::to_string(rand % 3) + std::to_string(rand % 100 / 10) + "-";
    rand = getRandom(i << 3);
    ans += std::to_string(rand % 10) + std::to_string(rand % 100 / 10);
    return ans;
}

const string streets[] = {
        "Podkolzina street",
        "street named after Matan",
        "Muravyov Amursky St.",
        "Blyukhera street",
        "The street of the one who must not be named",
        "street A-18",
        "Dikoboltsina street",
        "Str. Initiative",
        "Ilya Avenue",
        "Tankovodsky Avenue",
        "Mushroom street",
        "Elevatorskaya street"
};
const unsigned int streetsSize = 12;

string PhoneOwnerCut::getRandomAddress(int i) {
    return streets[getRandom(i * 8) % streetsSize] + " h. " + std::to_string(getRandom(i * 88) % 99 + 1) + " a. " +
           std::to_string(getRandom(i * 888) % 99 + 1);
}



