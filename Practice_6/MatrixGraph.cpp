//
// Created by gribk on 10.11.2023.
//

#include <iomanip>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertexCount) : vertexCount(vertexCount) {
    edgeCount = 0;
    matrix = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        matrix[i] = new int[vertexCount];
        for (int j = 0; j < vertexCount; j++)
            matrix[i][j] = 0;
    }
}

void MatrixGraph::insertEdge(int from, int to, int weight) {
    if (matrix[from][to] != 0)
        edgeCount++;
    matrix[from][to] = weight;
    matrix[to][from] = weight;
}

void MatrixGraph::print() {
    int numLen = getLenOfNumber(vertexCount - 1);
    int maxWeightLen = getLenOfNumber(getMaxWeight());
    int spaceCount = 1;
    if (maxWeightLen > numLen) {
        spaceCount += maxWeightLen - numLen;
    }

    cout << left << setw(numLen) << 0;
    for (int i = 1; i < vertexCount; i++)
        cout << string(spaceCount, ' ') << left << setw(numLen) << to_string(i);
    cout << endl;

    vector<string> out;
    out.push_back(string(numLen * vertexCount + vertexCount - 1, ' '));
    out.push_back(string(numLen * vertexCount + vertexCount - 1, ' '));
    for (int i = 0; i < vertexCount; i++) {
        for (int j = i; j < vertexCount; j++) {
            if (matrix[i][j] != 0) {
                out[0][i * (numLen + spaceCount)] = '|';
                out[0][j * (numLen + spaceCount)] = '|';
                out[1][i * (numLen + spaceCount)] = (char) 92;
                out[1][j * (numLen + spaceCount)] = '/';
                for (int k = i * (numLen + spaceCount) + 1; k < j * (numLen + spaceCount); k++)
                    out[1][k] = '_';
            }
        }
    }

    for (const string& line : out)
        cout << line << endl;
}

int MatrixGraph::getMaxWeight() {
    int max = 0;
    for (int i = 0; i < vertexCount; i++)
        for (int j = 0; j < vertexCount; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];
    return max;
}

int MatrixGraph::getLenOfNumber(int num) {
    return (int) to_string(num).length();
}
