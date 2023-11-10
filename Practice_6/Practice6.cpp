//
// Created by gribk on 10.11.2023.
//

#include "Practice6.h"

void Practice6::start() {
    cout << "Practice 6" << endl;
    cout << endl;

    unsigned int enter;

    auto graph = createGraph();
    cout << endl;

    cout << "Information about operations numbers:" << endl
         << "0 - exit;" << endl
         << "1 - print information;" << endl
         << "2 - create new graph;" << endl
         << "3 - print graph;" << endl
         << "4 - print matrix of graph;" << endl
         << "5 - insert edges;" << endl
         << "6 - get biggest value of leaf." << endl
         << endl;

    while (true) {
        cout << "Enter operation number or 0 for exit: ";
        cin >> enter;

        switch (enter) {

            case 0:
                cout << "Exit from practice 6" << endl;
                delete graph;
                return;

            case 1:
                cout << "Information about operations numbers:" << endl
                     << "0 - exit;" << endl
                     << "1 - print information;" << endl
                     << "2 - create new tree;" << endl
                     << "3 - print tree;" << endl
                     << "4 - get value of most left node;" << endl
                     << "5 - get path length to node with searched value;" << endl
                     << "6 - get biggest value of leaf." << endl;
                break;

            case 2:
                delete graph;
                graph = createGraph();
                break;

            case 3:
                cout << "Graph:" << endl;
                graph->print();
                break;

            case 4:
                cout << "Matrix of graph:" << endl;
                graph->printMatrix();
                break;

            case 5:
                insertEdges(graph);
                break;
//
//            case 6:
//                cout << "Biggest value of leaf: " << tree->getBiggestLeaf() << endl;
//                break;

            default:
                cout << "Error. Try again!" << endl;
        }
        cout << endl;
    }
}

MatrixGraph *Practice6::createGraph() {

    int enter;
    cout << "How many vortexes?: ";
    cin >> enter;
    auto graph = new MatrixGraph(enter);

    insertEdges(graph);

    cout << endl;
    cout << "Graph:" << endl;
    graph->print();

    return graph;
}

void Practice6::insertEdges(MatrixGraph *graph) {

    int enter, enter2;
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
}
