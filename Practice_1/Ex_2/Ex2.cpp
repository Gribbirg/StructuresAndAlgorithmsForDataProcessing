#include "Ex2.h"

void Ex2::start() {

    cout << "Exercise 2" << endl;

    unsigned int enter;
    unsigned int *mass;
    unsigned int size;

    while (true) {
        cout << "Enter part number or 0 for go back: ";
        cin >> enter;

        switch (enter) {

            case 0:
                cout << endl;
                return;

            case 1:
                cout << "Enter mass size: ";
                cin >> size;
                mass = new unsigned int[size];
                enterMass(mass, size);

                cout << setw(20) << "Massive before: " << massToLine(mass, size) << endl;
                mass = sortSizeEight(mass, size);
                cout << setw(20) << "Massive after: " << massToLine(mass, size) << endl;

                delete mass;
                break;

            case 2:
                cout << "Enter mass size: ";
                cin >> size;
                mass = new unsigned int[size];
                enterMass(mass, size);

                cout << setw(20) << "Massive before: " << massToLine(mass, size) << endl;
                mass = sortSizeSixtyFour(mass, size);
                cout << setw(20) << "Massive after: " << massToLine(mass, size) << endl;

                delete mass;
                break;

            default:
                cout << "Error. Try again!";
        }

        cout << endl;

    }

}

string Ex2::massToLine(unsigned int *mass, unsigned int size) {
    string ans;
    if (size == 0) return "";
    for (int i = 0; i < size; i++)
        ans +=  to_string(mass[i]) + ' ';

    ans.pop_back();
    return ans;
}

void Ex2::enterMass(unsigned int *mass, unsigned int size) {
    cout << "Enter mass elements (quantity " << size << "):" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << ":";
        cin >> mass[i];
    }
}

unsigned int *Ex2::sortSizeEight(unsigned int *mass, unsigned int size) {
    unsigned char isInMass = 0;
    unsigned int ansSize = 0;
    for (int i = 0; i < size; i++) {
        isInMass = setOneToPosition(isInMass, mass[i]);
    }
    int n = sizeof(unsigned char) * 8;
    unsigned mask = 1;
    for (int i = n; i >= 1; i--) {
        if (((isInMass & mask) >> (n - i)) == 1) {
            mass[ansSize] = n - i;
            ansSize++;
        }
        mask = mask << 1;
    }
    return mass;
}

unsigned char Ex2::setOneToPosition(unsigned char x, unsigned int position) {
    return x | (1 << position);
}

unsigned int *Ex2::sortSizeSixtyFour(unsigned int *mass, unsigned int size) {
    unsigned char isInMass[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < size; i++) {
        isInMass[7 - (mass[i] / 8)] = setOneToPosition(isInMass[7 - (mass[i] / 8)], mass[i] % 8);
    }
    int n = sizeof(unsigned char) * 8;
    unsigned int mask;
    unsigned int ansSize = 0;
    for (int j = 7; j >= 0; j--) {
        mask = 1;
        for (int i = n; i >= 1; i--) {
            if (((isInMass[j] & mask) >> (n - i)) == 1) {
                mass[ansSize] = n - i + 8 * (7 - j);
                ansSize++;
            }
            mask = mask << 1;
        }
    }
    return mass;
}


