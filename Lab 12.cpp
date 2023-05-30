#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int V = 6;

int minDistance(const vector<int>& dist, const vector<bool>& visited) {
    int min = numeric_limits<int>::max();
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printSolution(const vector<int>& dist, int src) {
    for (int i = 0; i < V; ++i) {
        cout << "Time taken from city " << src << " to city " << i << ": " << dist[i] << endl;
    }
}

void dijkstra(const vector<vector<int>>& graph, int source) {
    vector<int> dist(V, numeric_limits<int>::max());
    vector<bool> visited(V, false);

    dist[source] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, source);
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    for (int source = 0; source < V; ++source) {
        cout << "Source city: " << source << endl;
        dijkstra(graph, source);
        cout << endl;
    }

    return 0;
}
