//
// Created by gribk on 10.11.2023.
//

#ifndef STRUCTURESANDALGORITHMSFORDATAPROCESSING_MATRIXGRAPH_H
#define STRUCTURESANDALGORITHMSFORDATAPROCESSING_MATRIXGRAPH_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MatrixGraph {
private:

    int **matrix;
    int edgeCount;
    int vertexCount;

    int getMaxWeight();

    static int getLenOfNumber(int num);

    static bool checkForEmpty(string line, int start, int end);

    static string insertNumToCenter(string line, int num, int start, int end);

    void eulerCycle(int **matrixCopy, vector<int> &ans, int currentVertex);

    bool isEuler();

public:

    explicit MatrixGraph(int vertexCount);

    virtual ~MatrixGraph();

    void insertEdge(int from, int to, int weight);

    void print();

    void printMatrix();

    int getVertexCount() const;

    vector<int> getEulerCycle();
};


#endif //STRUCTURESANDALGORITHMSFORDATAPROCESSING_MATRIXGRAPH_H
