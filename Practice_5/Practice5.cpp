//
// Created by gribk on 29.10.2023.
//

#include "Practice5.h"
#include "PhoneOwnerCut.h"
#include "BinaryTrees/BinarySearchTree.h"
#include "SearchClasses/HashTableSearch.h"
#include "SearchClasses/BinFileSearch.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

void Practice5::start() {
    cout << "Practice 3" << endl;
    cout << endl;

    unsigned int enter;

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
                withFile<BinarySearchTree>();
            } else {
                withoutFile<BinarySearchTree>();
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
                withFile<HashTableSearch>();
            } else {
                withoutFile<HashTableSearch>();
            }
            break;
    }
}

template<class T>
void Practice5::withoutFile() {
    cout << endl;
    int enter, i = 0;
    string phone;
    ISearchClass *searchObject = new T();

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

        switch (enter) {

            case 0:
                cout << "Exit from practice 3" << endl;
                delete searchObject;
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

                if (searchObject->deleteElement(phone) != -1)
                    cout << "Phone " << phone << " was deleted!" << endl;
                else
                    cout << "Phone " << phone << " isn't in the table!" << endl;

                break;

            default:
                cout << "Error. Try again!" << endl;
        }
        cout << endl;
    }
}

template<class T>
void Practice5::withFile() {
//    fstream fstream1;
//    fstream fstream2;
    int enter;
    cout << "Create new file? (1 - yes, 0 - no): ";
    cin >> enter;
    BinFileSearch *binFile;
    if (enter == 1) {
        cout << "Enter file size: ";
        cin >> enter;
        binFile = new BinFileSearch(new T(), "bin.dat", enter);
    } else {
        binFile = new BinFileSearch(new T(), "bin.dat");
    }
    cout << endl;

    string phone;
    string s;
    PhoneOwnerCut phoneOwner;

    cout << "Information about operations numbers:" << endl
         << "0 - exit from practice 5;" << endl
         << "1 - print operations info;" << endl
         << "2 - print struct;" << endl
         << "3 - print data from bin file;" << endl
         << "4 - find element;" << endl
         << "5 - insert element;" << endl
         << "6 - insert many random elements;" << endl
         << "7 - delete element." << endl
         << endl;

    while (true) {
        cout << "Enter operation number or 0 for exit: ";
        cin >> enter;
        cout << endl;

        switch (enter) {

            case 0:
                cout << "Exit from exercise 3" << endl;
                delete binFile;
                return;

            case 1:
                cout << "Information about operations numbers:" << endl
                     << "0 - exit from practice 5;" << endl
                     << "1 - print operations info;" << endl
                     << "2 - print struct;" << endl
                     << "3 - print data from bin file;" << endl
                     << "4 - find element;" << endl
                     << "5 - insert element;" << endl
                     << "6 - insert many random elements;" << endl
                     << "7 - delete element." << endl;
                break;

            case 2:
                binFile->printStruct();
                break;

            case 3:
                binFile->readAll();
                break;

            case 4:
                cout << "Enter the phone number you are looking for (format: +7 (XXX) XXX-XX-XX): ";
                while (getline(cin, phone) && phone.empty());
                cout << endl;

                phoneOwner = binFile->find(phone);
                if (phoneOwner.phone[0] == 0)
                    cout << "The phone " << phone << " isn't in the file!" << endl;
                else
                    cout << phoneOwner.to_string() << endl;

                phone = "";
                phoneOwner = PhoneOwnerCut();
                break;

            case 5:
                cout
                        << "Enter the phone number you want to insert (format: +7 (XXX) XXX-XX-XX) or 0 to insert random: ";
                while (getline(cin, phone) && phone.empty());
                cout << endl;

                if (phone == "0") {
                    do {
                        phoneOwner = PhoneOwnerCut::getRandomOwner((int) binFile->getSize());
                    } while (!binFile->insert(phoneOwner));
                    cout << "Phone " << phoneOwner.phone << " is now in the bin file!" << endl;
                } else {

                    strcpy(phoneOwner.phone, phone.c_str());

                    cout << "Enter the address: ";
                    while (getline(cin, s) && s.empty());
                    cout << endl;
                    strcpy(phoneOwner.address, s.c_str());
                    s = "";


                    if (binFile->insert(phoneOwner)) {
                        cout << "Phone " << phone << " is now in the bin file!" << endl;
                    } else
                        cout << "Phone " << phone << " is already in the bin file!" << endl;
                }
                phone = "";
                break;

            case 6:

                cout << "How many elements you want to insert: ";
                cin >> enter;

                for (int j = 0; j < enter; j++) {
                    while (!binFile->insert(PhoneOwnerCut::getRandomOwner((int) binFile->getSize())));
                }
                cout << "Done!" << endl;

                break;

            case 7:

                cout << "Enter the phone number you want to delete (format: +7 (XXX) XXX-XX-XX): ";
                while (getline(cin, phone) && phone.empty());

                cout << endl;
                if (binFile->deleteElement(phone))
                    cout << "Phone " << phone << " was deleted!" << endl;
                else
                    cout << "Phone " << phone << " isn't in the table!" << endl;

                break;


            default:
                cout << "Error. Try again!" << endl;
        }
        cout << endl;
    }
}