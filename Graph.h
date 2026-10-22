// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
class Graph {
    vector<vector<T>> adj_matrix;
    int num_vertices;

public:
    Graph(int n);

    void add_edge(int u, int v, T weight = T(1));
    void print_matrix() const;
    vector<int> bfs_shortest_path(int start, int goal) const;

private:
    void print_matrix_helper(const vector<vector<T>>& matrix) const;

    vector<int> bfs(const vector<vector<T>>& matrix,
                    int n, int start, int goal) const;

    void reconstruct_path(const unordered_map<int, int>& parent,
                          int goal,
                          vector<int>& path) const;
};

#include "Graph.cpp"

#endif 
