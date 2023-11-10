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

    int enter, enter2;
    cout << "How many vortexes?: ";
    cin >> enter;
    auto graph = new MatrixGraph(enter);

    cout << "How many edges?: ";
    cin >> enter;
    cout << "Random? (1 - yes, 0 - no): ";
    cin >> enter2;

    int start, end;
    if (enter2 == 1) {
        for (int i = 0; i < enter; i++) {
            do {
                start = rand() % graph->getVertexCount();
                end = rand() % graph->getVertexCount();
            } while (start == end);
            graph->insertEdge(start, end, rand() % 100);
        }
    } else {
        int weight;
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
