#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int source, destination, weight;
};

struct Subset {
    int parent, rank;
};

int findParent(std::vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findParent(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSubsets(std::vector<Subset>& subsets, int x, int y) {
    int xRoot = findParent(subsets, x);
    int yRoot = findParent(subsets, y);

    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

std::vector<Edge> findMST(std::vector<std::vector<int>>& graph, int numVertices) {
    std::vector<Edge> result;

    std::vector<Edge> edges;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({ i, j, graph[i][j] });
            }
        }
    }
    std::sort(edges.begin(), edges.end(), compareEdges);

    std::vector<Subset> subsets(numVertices);
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeIndex = 0;
    int numEdges = 0;
    while (numEdges < numVertices - 1 && edgeIndex < edges.size()) {
        Edge nextEdge = edges[edgeIndex++];

        int x = findParent(subsets, nextEdge.source);
        int y = findParent(subsets, nextEdge.destination);

        if (x != y) {
            result.push_back(nextEdge);
            unionSubsets(subsets, x, y);
            numEdges++;
        }
    }

    return result;
}

void printMST(const std::vector<Edge>& mst) {
    int totalWeight = 0;

    std::cout << "Minimum Spanning Tree (MST):\n";
    for (const Edge& edge : mst) {
        std::cout << edge.source << " - " << edge.destination << " : " << edge.weight << "\n";
        totalWeight += edge.weight;
    }

    std::cout << "Total weight: " << totalWeight << "\n";
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int numVertices = graph.size();

    std::vector<Edge> mst = findMST(graph, numVertices);
    printMST(mst);

    return 0;
}
