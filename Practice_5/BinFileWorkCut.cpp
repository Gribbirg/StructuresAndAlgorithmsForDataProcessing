//
// Created by gribk on 04.10.2023.
//

#include "BinFileWorkCut.h"

#include <utility>
#include <algorithm>
#include <cstring>
#include <random>

BinFileWorkCut::BinFileWorkCut(string fileName): fileName(std::move(fileName)) {}

void BinFileWorkCut::fillFileWithRandom(int count) {
    vector<string> numbers;

    string number;
    for (int i = 0; i < count; i++) {
        number = PhoneOwnerCut::getRandomPhoneNumber(i);

        while (binary_search(numbers.begin(), numbers.end(), number))
            number = PhoneOwnerCut::getRandomPhoneNumber(i);

        numbers.push_back(number);
    }

    shuffle(numbers.begin(), numbers.end(), std::mt19937(std::random_device()()));

    file.open("enter.txt", ios::out | ios::trunc);
    if (file.is_open()) {
        if (!numbers.empty()) {
            file << numbers[0] << "\n" << PhoneOwnerCut::getRandomAddress(0);
            for (int i = 1; i < count; i++) {
                file << "\n" << numbers[i] << "\n" << PhoneOwnerCut::getRandomAddress(i);
            }
        }
    } else {
        cout << "Error while opening file!" << endl;
        exit(0);
    }
    file.close();
}

void BinFileWorkCut::readAll() {
    file.open(fileName, ios::in | ios::binary);

    if (!file.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(0);
    }

    PhoneOwnerCut phoneOwner{};
    file.read((char *) &phoneOwner, sizeof(PhoneOwnerCut));
    int i = 0;
    while (!file.eof()) {
        cout << i << ": " << phoneOwner.to_string() << endl;
        i++;
        file.read((char *) &phoneOwner, sizeof(PhoneOwnerCut));
    }
    file.close();
}

PhoneOwnerCut BinFileWorkCut::getElement(unsigned int position) {
    file.open(fileName, ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(0);
    }

    PhoneOwnerCut phoneOwner{};

    file.seekg(position * sizeof(PhoneOwnerCut), ios::beg);
    file.read((char *) &phoneOwner, sizeof(PhoneOwnerCut));

    file.close();

    return phoneOwner;
}

void BinFileWorkCut::fillBinFile(int count) {
    fillFileWithRandom(count);
    fillBinFromEnter();
}

void BinFileWorkCut::insert(PhoneOwnerCut phoneOwner, unsigned int position) {
    file.open(fileName, ios::out | ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(0);
    }
    file.seekg(position * sizeof(PhoneOwnerCut), ios::beg);
    file.write((char *) &phoneOwner, sizeof(PhoneOwnerCut));
    file.close();
}

void BinFileWorkCut::fillBinFromEnter() {
    file1.open("enter.txt", ios::in);
    file.open(fileName, ios::out | ios::binary | ios::trunc);

    if (!file1.is_open() || !file.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(0);
    }

    PhoneOwnerCut phoneOwner{};
    string phone;
    string address;
    string fullName;

    while (!file1.eof()) {
        getline(file1, phone);
        getline(file1, address);
        getline(file1, fullName);

        strcpy(phoneOwner.phone, phone.c_str());
        strcpy(phoneOwner.address, address.c_str());

        file.write((char *) &phoneOwner, sizeof(PhoneOwnerCut));
    }

    file1.close();
    file.close();
}


