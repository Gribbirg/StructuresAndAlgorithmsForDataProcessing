//
// Created by gribk on 29.10.2023.
//

#include "Practice5.h"
#include "PhoneOwnerCut.h"
#include "BinaryTrees/BinarySearchTree.h"
#include "SearchClasses/HashTableSearch.h"
#include <iostream>
#include <fstream>

using namespace std;

void Practice5::start() {
    cout << "Practice 3" << endl;
    cout << endl;

    unsigned int enter;
    fstream fstream1;
    fstream fstream2;

    cout << "Search structures:" << endl
         << "1 - binary search tree;" << endl
         << "2 - split binary search tree;" << endl
         << "3 - hash table." << endl;
    cout << "What to use?: ";
    cin >> enter;
    cout << endl;

    switch (enter) {

        case 1:
            cout << "Work with binary search tree" << endl;
            cout << "Use bin file? (1 - yes, 0 - no): ";
            cin >> enter;

            if (enter == 1) {
                withFile(new BinarySearchTree());
            } else {
                withoutFile(new BinarySearchTree());
            }

            break;

//        case 2:
//            cout << "Work with binary search tree" << endl;
//            cout << "Use bin file? (1 - yes, 0 - no): " << endl;
//            cin >> enter;
//
//            if (enter == 1) {
//                withFile(new BinarySearchTree());
//            } else {
//                withoutFile(new BinarySearchTree());
//            }
//            break;

        case 3:
            cout << "Work with hash table" << endl;
            cout << "Use bin file? (1 - yes, 0 - no): " << endl;
            cin >> enter;

            if (enter == 1) {
                withFile(new HashTableSearch());
            } else {
                withoutFile(new HashTableSearch());
            }
    }
}


void Practice5::withoutFile(ISearchClass *searchObject) {
    fstream fstream1;
    int enter, i = 0;
    string phone;

    cout << "Information about operations numbers:" << endl
         << "0 - exit from without file mode;" << endl
         << "1 - print operations info;" << endl
         << "2 - print table;" << endl
         << "3 - find element;" << endl
         << "4 - insert element;" << endl
         << "5 - insert many random elements;" << endl
         << "6 - delete element." << endl
         << endl;

    while (true) {
        cout << "Enter operation number or 0 for exit: ";
        cin >> enter;
        cout << endl;

        switch (enter) {

            case 0:
                cout << "Exit from practice 3" << endl;
                return;

            case 1:
                cout << "Information about operations numbers:" << endl
                     << "0 - exit from without file mode;" << endl
                     << "1 - print operations info;" << endl
                     << "2 - print struct;" << endl
                     << "3 - find element;" << endl
                     << "4 - insert element;" << endl
                     << "5 - insert many random elements;" << endl
                     << "6 - delete element." << endl;
                break;

            case 2:
                searchObject->print();
                break;

            case 3:
                cout << "Enter the phone number you are looking for (format: +7 (XXX) XXX-XX-XX): ";
                while (getline(cin, phone) && phone.empty());
                cout << endl;

                enter = searchObject->find(phone);
                if (enter == -1)
                    cout << "The phone " << phone << " isn't in the table!" << endl;
                else
                    cout << "The position of phone " << phone << " is " << enter << endl;

                phone = "";
                break;

            case 4:
                cout
                        << "Enter the phone number you want to insert (format: +7 (XXX) XXX-XX-XX) or 0 to insert random: ";
                while (getline(cin, phone) && phone.empty());

                if (phone == "0") phone = PhoneOwnerCut::getRandomPhoneNumber(i);

                cout << endl;
                if (searchObject->insert(phone, i)) {
                    cout << endl << "Phone " << phone << " is now in the table!" << endl;
                    i++;
                } else
                    cout << "Phone " << phone << " is already in the table!" << endl;

                break;

            case 5:

                cout << "How many elements you want to insert: ";
                cin >> enter;

                for (int j = 0; j < enter; j++) {
                    while (!searchObject->insert(PhoneOwnerCut::getRandomPhoneNumber(i), i))
                        i++;
                    i++;
                }
                cout << "Done!" << endl;

                break;

            case 6:

                cout << "Enter the phone number you want to delete (format: +7 (XXX) XXX-XX-XX): ";
                while (getline(cin, phone) && phone.empty());

                cout << endl;
                if (searchObject->deleteElement(phone) != -1)
                    cout << "Phone " << phone << " was deleted!" << endl;
                else
                    cout << "Phone " << phone << " isn't in the table!" << endl;

                break;

            default:
                cout << "Error. Try again!" << endl;
        }
        cout << endl << endl;
    }
}

void Practice5::withFile(ISearchClass *searchObject) {

}
