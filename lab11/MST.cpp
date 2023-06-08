#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinimumDistanceNode(vector<int>& distances, vector<bool>& visited, int numNodes) {
    int minimumDistance = INT_MAX;
    int minimumNode = -1;

    for (int node = 0; node < numNodes; ++node) {
        if (!visited[node] && distances[node] < minimumDistance) {
            minimumDistance = distances[node];
            minimumNode = node;
        }
    }

    return minimumNode;
}

void primsAlgorithm(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    vector<int> distances(numNodes, INT_MAX);
    vector<bool> visited(numNodes, false);
    vector<int> parent(numNodes, -1);

    distances[startNode] = 0;

    for (int count = 0; count < numNodes - 1; ++count) {
        int currentNode = findMinimumDistanceNode(distances, visited, numNodes);
        visited[currentNode] = true;

        for (int node = 0; node < numNodes; ++node) {
            if (graph[currentNode][node] != 0 && !visited[node] && graph[currentNode][node] < distances[node]) {
                distances[node] = graph[currentNode][node];
                parent[node] = currentNode;
            }
        }
    }

    cout << "Minimum Spanning Tree Edges:" << endl;
    int totalCost = 0;
    for (int node = 0; node < numNodes; ++node) {
        if (node != startNode) {
            cout << parent[node] << " - " << node << endl;
            totalCost += graph[node][parent[node]];
        }
    }

    cout << "Total Cost of the Minimum Spanning Tree: " << totalCost << endl;
}

int main() {
    int numNodes = 6; // Number of nodes in the graph

    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startNode;
    cout << "Enter the starting node (0-5): ";
    cin >> startNode;

    primsAlgorithm(graph, startNode);

    return 0;
}
