#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> intPair;

vector<int> dijkstra(vector<vector<intPair>>& graph, int source) {
    int n = graph.size();

    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    priority_queue<intPair, vector<intPair>, greater<intPair>> priorityQueue;
    priorityQueue.push({0, source});

    while (!priorityQueue.empty()) {
        int u = priorityQueue.top().second;
        int dist = priorityQueue.top().first;
        priorityQueue.pop();

        if (dist > distance[u]) {
            continue;
        }

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                priorityQueue.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    int numNodes = 6;
    int source;

    cout<<"Enter the source vertex: ";
    cin>>source;

    vector<vector<intPair>> graph(numNodes);

    int edges[][3] = {
        {0, 1, 10},
        {0, 4, 15},
        {0, 5, 5},
        {1, 2, 10},
        {2, 3, 12},
        {2, 4, 5},
        {3, 5, 20}
    };

    int numEdges = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < numEdges; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    vector<int> shortestDistances = dijkstra(graph, source);

    cout << "Shortest time from the city " << source << ":" << endl;
    for (int i = 0; i < numNodes; ++i) {
        cout << "City " << source << " to City " << i<<" : " << shortestDistances[i] << endl;
    }

    return 0;
}
