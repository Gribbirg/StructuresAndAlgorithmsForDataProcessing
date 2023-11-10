//
// Created by gribk on 10.11.2023.
//

#include <iomanip>
#include <algorithm>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertexCount) : vertexCount(vertexCount) {
    edgeCount = 0;
    matrix = new int *[vertexCount];
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

    cout << left << setw(numLen) << 1;
    for (int i = 1; i < vertexCount; i++)
        cout << string(spaceCount, ' ') << left << setw(numLen) << i + 1;
    cout << endl;

    vector<string> out;
    out.emplace_back(numLen * vertexCount + vertexCount * spaceCount - spaceCount, ' ');
    out.emplace_back(numLen * vertexCount + vertexCount * spaceCount - spaceCount, ' ');
    int lineNum, start, end;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = i; j < vertexCount; j++) {
            if (matrix[i][j] != 0) {
                start = i * (numLen + spaceCount);
                end = j * (numLen + spaceCount);
                out[0][start] = '|';
                out[0][end] = '|';
                lineNum = 1;
                while (!checkForEmpty(out[lineNum], start, end)) {
                    if (out[lineNum][start] == ' ') out[lineNum][start] = '|';
                    if (out[lineNum][start] == '-') out[lineNum][start] = '+';
                    if (out[lineNum][end] == ' ') out[lineNum][end] = '|';
                    if (out[lineNum][end] == '-') out[lineNum][end] = '+';
                    lineNum++;
                    if (lineNum + 1 > out.size())
                        out.emplace_back(numLen * vertexCount + vertexCount * spaceCount - spaceCount, ' ');
                }
                out[lineNum][start] = (char) 92;
                out[lineNum][end] = '/';
                for (int k = start + 1; k < end; k++)
                    out[lineNum][k] = '-';
                out[lineNum] = insertNumToCenter(out[lineNum], matrix[i][j], start, end);
            }
        }
    }

    for (const string &line: out)
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

bool MatrixGraph::checkForEmpty(string line, int start, int end) {
    for (int i = start; i < end + 1; i++) {
        if (line[i] != ' ') return false;
    }
    return true;
}

string MatrixGraph::insertNumToCenter(string line, int num, int start, int end) {
    int numLen = getLenOfNumber(num);
    int startPrint = (end - start) / 2 + (end - start) % 2 - numLen / 2 + start;
    for (int i = 0; i < numLen; i++) {
        line[i + startPrint] = to_string(num)[i];
    }
    return line;
}

int MatrixGraph::getVertexCount() const {
    return vertexCount;
}

void MatrixGraph::printMatrix() {
    int numLen = max(getLenOfNumber(getMaxWeight()), getLenOfNumber(vertexCount - 1));

    cout << left << setw(numLen) << ' ';
    for (int i = 0; i < vertexCount; i++) {
        cout << ' ' << left << setw(numLen) << i + 1;
    }
    cout << endl;

    for (int i = 0; i < vertexCount; i++) {
        cout << left << setw(numLen) << i + 1;
        for (int j = 0; j < vertexCount; j++) {
            cout << ' ' << left << setw(numLen) << matrix[i][j];
        }
        cout << endl;
    }
}

MatrixGraph::~MatrixGraph() {
    for (int i = 0; i < vertexCount; i++)
        delete[] matrix[i];
    delete[] matrix;
}

vector<int> MatrixGraph::getEulerCycle() {

    if (!isEuler())
        return {};

    int **matrixCopy = new int *[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        matrixCopy[i] = new int[vertexCount];
        for (int j = 0; j < vertexCount; j++)
            matrixCopy[i][j] = matrix[i][j];
    }

    vector<int> ans;
    eulerCycle(matrixCopy, ans, 0);

    for (int i = 0; i < vertexCount; i++)
        delete[] matrixCopy[i];
    delete[] matrixCopy;

    for (int i = 0; i < vertexCount; i++) {
        if (find(ans.begin(), ans.end(), i) == ans.end()) {
            ans.clear();
            break;
        }
    }

    return ans;
}

void MatrixGraph::eulerCycle(int **matrixCopy, vector<int> &ans, int currentVertex) {
    for (int i = 0; i < vertexCount; i++) {
        if (matrixCopy[currentVertex][i] != 0) {
            matrixCopy[i][currentVertex] = matrixCopy[currentVertex][i] = 0;
            eulerCycle(matrixCopy, ans, i);
        }
    }
    ans.push_back(currentVertex);
}

bool MatrixGraph::isEuler() {
    int oddCount = 0;
    int count;
    for (int i = 0; i < vertexCount; i++) {
        count = 0;
        for (int j = 0; j < vertexCount; j++) {
            if (matrix[i][j] != 0)
                count++;
        }
        if (count % 2 != 0)
            oddCount++;
        else if (count == 0)
            return false;
    }
    if (oddCount > 2) return false;



    return true;
}
