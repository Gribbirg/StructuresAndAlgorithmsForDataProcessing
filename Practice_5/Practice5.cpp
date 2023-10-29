//
// Created by gribk on 29.10.2023.
//

#include "Practice5.h"
#include <iostream>
#include <fstream>

using namespace std;

void Practice5::start() {
    cout << "Practice 3" << endl;
    cout << endl;

    unsigned int enter;
    fstream fstream1;
    fstream fstream2;

    while (true) {
        cout << "Enter exercise number or 0 for exit: ";
        cin >> enter;
        cout << endl;

        switch (enter) {

            case 0:
                cout << "Exit from practice 3" << endl;
                return;

            case 1:
                cout << "Exercise 1" << endl;

                break;

            case 2:
                cout << "Exercise 2" << endl;

                break;

            case 3:
                cout << "Exercise 3" << endl;

                break;

            default:
                cout << "Error. Try again!" << endl;
        }
        cout << endl;
    }
}
