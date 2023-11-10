//
// Created by gribk on 10.11.2023.
//

#include "Practice6.h"

void Practice6::start() {
    cout << "Practice 6" << endl;
    cout << endl;

    unsigned int enter;

    MatrixGraph *graph = new MatrixGraph(11);
    graph->insertEdge(0, 8, 5);
    graph->insertEdge(2, 10, 5);
    graph->insertEdge(5, 8, 5);
    graph->insertEdge(1, 3, 1);
    graph->insertEdge(1, 0, 1);
    graph->print();

//    while (true) {
//        cout << "Search structures:" << endl
//             << "0 - exit;" << endl
//             << "1 - binary search tree;" << endl
//             << "2 - splay binary search tree;" << endl
//             << "3 - hash table;" << endl
//             << "9 - comparison." << endl;
//        cout << "What to use?: ";
//        cin >> enter;
//        cout << endl;
//        switch (enter) {
//            case 0:
//                cout << "Exit from practice 5." << endl;
//                return;
//
//            case 1:
//                cout << "Work with binary search tree." << endl;
//                cout << "Use bin file? (1 - yes, 0 - no): ";
//                cin >> enter;
//
//                if (enter == 1) {
//                    withFile<BinarySearchTree>();
//                } else {
//                    withoutFile<BinarySearchTree>();
//                }
//
//                break;
//
//            case 2:
//                cout << "Work with splay binary tree." << endl;
//                cout << "Use bin file? (1 - yes, 0 - no): ";
//                cin >> enter;
//
//                if (enter == 1) {
//                    withFile<SplayTree>();
//                } else {
//                    withoutFile<SplayTree>();
//                }
//                break;
//
//            case 3:
//                cout << "Work with hash table." << endl;
//                cout << "Use bin file? (1 - yes, 0 - no): ";
//                cin >> enter;
//
//                if (enter == 1) {
//                    withFile<HashTableSearch>();
//                } else {
//                    withoutFile<HashTableSearch>();
//                }
//                break;
//
//            case 9:
//                comparison();
//                break;
//
//            default:
//                cout << "Error. Try again!" << endl;
//        }
//        cout << endl;
//    }
}
