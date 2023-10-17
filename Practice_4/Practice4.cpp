//
// Created by gribk on 16.10.2023.
//

#include "Practice4.h"


void Practice4::start() {
    cout << "Practice 4" << endl;
    cout << endl;

    unsigned int enter;
    char ch;

    PerfectlyBalancedBinaryTree *tree = createTree();
    cout << endl;

    cout << "Information about operations numbers:" << endl
         << "0 - exit;" << endl
         << "1 - create new tree;" << endl
         << "2 - print tree;" << endl
         << "3 - get value of most left node;" << endl
         << "4 - get path length to node with searched value." << endl
         << endl;

    while (true) {
        cout << "Enter operation number or 0 for exit: ";
        cin >> enter;
        cout << endl;

        switch (enter) {

            case 0:
                cout << "Exit from practice 4" << endl;
                return;

            case 1:
                delete tree;
                tree = createTree();
                break;

            case 2:
                tree->print();
                break;

            case 3:
                cout << "Most left value: " << tree->getMostLeftNode() << endl;
                break;

            case 4:
                cout << "Enter searched value: ";
                cin >> ch;
                enter = tree->getPathLengthToNode(ch);
                if (enter != -1)
                    cout << "Path length to '" << ch << "' = " << enter << endl;
                else
                    cout << "Char '" << ch << "' isn't in the tree!" << endl;
                break;

            default:
                cout << "Error. Try again!" << endl;
        }
        cout << endl;
    }


}

PerfectlyBalancedBinaryTree *Practice4::createTree() {
    int n;
    bool random;
    cout << "How much elements?: ";
    cin >> n;
    cout << "Random values? (1 - yes, 0 - no): ";
    cin >> random;

    vector<char> values;
    char val;

    if (random) {
        for (int i = 0; i < n; i++) {
            srand((unsigned) (time(nullptr) * (i + 8)));
            values.push_back(rand() % 94 + 33);
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            cin >> val;
            values.push_back(val);
        }
    }
    return new PerfectlyBalancedBinaryTree(n, values);
}