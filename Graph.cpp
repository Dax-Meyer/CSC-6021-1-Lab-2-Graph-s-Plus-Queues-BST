
#include <iostream>
#include <queue>
#include <algorithm>
#include "Graph.h"
using namespace std;

template <typename T>
Graph<T>::Graph(int n) {
    num_vertices = n;
    adj_matrix = vector<vector<T>>(n, vector<T>(n, T(0)));
}

template <typename T>
void Graph<T>::add_edge(int u, int v, T weight) {
    adj_matrix[u][v] = weight;
    adj_matrix[v][u] = weight;
}

template <typename T>
void Graph<T>::print_matrix() const {
    print_matrix_helper(adj_matrix);
}

template <typename T>
void Graph<T>::print_matrix_helper(const vector<vector<T>>& matrix) const {
    cout << "\n=== Adjacency Matrix ===" << endl;
    for (const vector<T>& row : matrix) {
        for (const T& val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

template <typename T>
vector<int> Graph<T>::bfs_shortest_path(int start, int goal) const {
    return bfs(adj_matrix, num_vertices, start, goal);
}

template <typename T>
vector<int> Graph<T>::bfs(const vector<vector<T>>& matrix,
                           int n, int start, int goal) const {
    queue<int> q;
    unordered_map<int, int> parent;
    vector<bool> visited(n, false);

    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    cout << "\n=== BFS Traversal Order ===" << endl;
    cout << "Visiting: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        if (node == goal) {
            cout << "\n\nGoal node " << goal << " reached!" << endl;
            vector<int> path;
            reconstruct_path(parent, goal, path);
            return path;
        }

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (matrix[node][neighbor] != T(0) && !visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    cout << "\nNo path found!" << endl;
    return {};
}

template <typename T>
void Graph<T>::reconstruct_path(const unordered_map<int, int>& parent,
                                 int goal,
                                 vector<int>& path) const {
    for (int at = goal; at != -1; at = parent.at(at))
        path.push_back(at);
    reverse(path.begin(), path.end());
}
