#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Graph {
    int x1, y1;
    int x2, y2;
    int weight;
};

vector<Graph> readGraphFromFile(const string& filename) {
    vector<Graph> graphList;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        Graph temp;
        while (inputFile >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2) {
            graphList.push_back(temp);
        }
        inputFile.close();
    }
    else {
        cout << "Error opening file" << endl;
    }

    return graphList;
}

void calculateWeightForEdges(vector<Graph>& graphList) {
    for (auto& edge : graphList) {
        edge.weight = sqrt((edge.x2 - edge.x1) * (edge.x2 - edge.x1) + (edge.y2 - edge.y1) * (edge.y2 - edge.y1));
    }
}

void displayEdges(const vector<Graph>& graphList, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& edge : graphList) {
            outputFile << "(" << edge.x1 << "," << edge.y1 << ") - (" << edge.x2 << "," << edge.y2 << ") : " << edge.weight << endl;
        }
        outputFile.close();
    }
    else {
        cout << "Error opening file" << endl;
    }
}

int main() {
    vector<Graph> graphList = readGraphFromFile("graph.txt");

    calculateWeightForEdges(graphList);

    displayEdges(graphList, "output.txt");

    return 0;
}