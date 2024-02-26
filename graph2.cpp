#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Edge {
    int x;
    int y;
    int weight;
};

class Graph {
private:
    vector<Edge> adjacencyList;

public:
    void readFromFile(const string& filename) {
        ifstream file(filename);
        int vertex1, vertex2, weight;
        while (file >> vertex1 >> vertex2 >> weight) {
            Edge edge{ vertex1, vertex2, weight };
            adjacencyList.push_back(edge);
        }
    }

    void showGraph(const string& filename) {
        ofstream file(filename);
        for (const Edge& edge : adjacencyList) {
            file << "Vertex " << edge.x << " is connected to vertex " << edge.y << " with weight " << edge.weight << endl;
        }
    }

    bool hasEdge(int vertex1, int vertex2) {
        for (const Edge& edge : adjacencyList) {
            if ((edge.x == vertex1 && edge.y == vertex2) || (edge.x == vertex2 && edge.y == vertex1)) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> createAdjacencyMatrix(int numVertices) {
        vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));
        for (const Edge& edge : adjacencyList) {
            adjacencyMatrix[edge.x][edge.y] = edge.weight;
            adjacencyMatrix[edge.y][edge.x] = edge.weight;
        }
        return adjacencyMatrix;
    }
};

int main() {
    Graph graph;
    graph.readFromFile("input.txt");
    graph.showGraph("output.txt");
    bool exists = graph.hasEdge(0, 1);
    cout << "Edge between vertex 0 and vertex 1 exists: " << boolalpha << exists << endl;
    vector<vector<int>> adjacencyMatrix = graph.createAdjacencyMatrix(5);
    return 0;
}