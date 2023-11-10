//
// Created by gribk on 10.11.2023.
//

#include "Practice6.h"

void Practice6::start() {
    cout << "Practice 6" << endl;
    cout << endl;

    unsigned int enter;

    auto graph = createGraph();
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

MatrixGraph *Practice6::createGraph() {

    int enter;
    cout << "How many vortexes? (0 - random from 1 to 100): ";
    cin >> enter;
    auto graph = new MatrixGraph((enter == 0) ? rand() % 99 + 1 : enter);

    cout << "How many edges? (0 - random edges): ";
    cin >> enter;

    if (enter == 0) {
        for (int i = 0; i < graph->getVertexCount(); i++) {
            for (int j = i + 1; j < graph->getVertexCount(); j++) {
                if (rand() % 100 < 2)
                    graph->insertEdge(i, j, rand() % 100);
            }
        }
    } else {
        int start, end, weight;
        for (int i = 0; i < enter; i++) {
            cout << i << ":" << endl;
            cout << "From vertex with num: ";
            cin >> start;
            cout << "To vertex with num: ";
            cin >> end;
            cout << "Weight: ";
            cin >> weight;
            graph->insertEdge(start, end, weight);
        }
    }

    return graph;
}
