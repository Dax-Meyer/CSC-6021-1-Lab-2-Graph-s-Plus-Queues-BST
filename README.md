# Graph Navigation and Shortest Path Finder in C++

## Project Overview

This project demonstrates how **graph data structures** and the **Breadth-First Search (BFS)** algorithm work together to explore connections and find a shortest path between two nodes.

The program provides an interactive, menu-driven way to build a graph, view its connections as an adjacency matrix, and search for a path between a starting node and a destination. It is a practical learning example for core data-structures and algorithms concepts in C++.

## The Theory Behind the Project

### What Is a Graph?

A graph is a non-linear data structure used to represent objects and the relationships between them. It consists of:

- **Vertices (nodes):** The objects in the graph. In this program, nodes are identified by numbers.
- **Edges:** The connections between nodes.

Graphs can represent road networks, social relationships, computer networks, and many other connected systems.

### What Is an Adjacency Matrix?

An adjacency matrix is a table used to represent which nodes are connected. Each row and column corresponds to a node. A cell indicates whether an edge exists between the node represented by that row and the node represented by that column.

For a simple unweighted graph, `1` commonly means an edge exists, while `0` means there is no edge. The program displays this matrix so the graph's connections can be inspected.

An adjacency matrix is easy to understand and makes direct-connection checks straightforward. Its trade-off is memory: it uses space proportional to **O(V²)**, where **V** is the number of vertices, even when relatively few edges exist.

### What Is Breadth-First Search (BFS)?

Breadth-First Search is a graph-traversal algorithm that explores outward from a starting node, visiting nearby nodes before moving to nodes farther away.

BFS uses a **queue**, which follows the **First-In, First-Out (FIFO)** rule: the first node added is the first node removed for processing.

At a high level, BFS works like this:

1. Add the starting node to the queue and mark it as visited.
2. Remove the node at the front of the queue.
3. Examine its neighboring nodes.
4. Mark each newly discovered neighbor as visited and add it to the back of the queue.
5. Continue until the destination is found or there are no more nodes to process.

Marking nodes as visited prevents the search from repeatedly processing the same node, including when the graph contains cycles or multiple routes to a node.

### Why Can BFS Find a Shortest Path?

In an **unweighted graph**, every edge is treated as having the same cost. Because BFS explores nodes in order of their distance from the starting node, it can find a path with the **fewest edges** to a reachable destination.

This does not necessarily mean the fastest or cheapest real-world route. If connections have different distances, travel times, or costs, algorithms such as Dijkstra's algorithm or A* are generally more appropriate.

## What the Program Does

The program provides four menu options:

1. **Add edges** — enter connections between nodes to build the graph.
2. **Display graph** — show the graph's adjacency matrix.
3. **Find shortest path** — enter a starting node and destination, then use BFS to search for a path.
4. **Exit** — close the program.

The demonstration focuses on running the program rather than explaining every line of source code. It shows how the graph changes as edges are added, how the adjacency matrix represents those connections, and how the shortest-path feature explores the graph.

## Example Demonstration

Create an example graph by adding these connections:

- Node `0` to node `1`
- Node `0` to node `2`
- Node `1` to node `2`
- Node `1` to node `3`
- Node `2` to node `3`

Display the adjacency matrix to inspect the connections. Then select the shortest-path option and search from node `0` to node `3`.

Possible shortest routes include `0 → 1 → 3` and `0 → 2 → 3`. Each route uses two edges, so either is a shortest path. The exact route displayed can depend on the order in which neighboring nodes are examined.

## Efficiency and Complexity

Let **V** be the number of vertices and **E** be the number of edges.

For a graph stored as an **adjacency matrix**:

- **Storage:** O(V²), because the matrix has a row and column for every vertex.
- **BFS traversal:** typically O(V²), because the algorithm may scan an entire matrix row to find each node's neighbors.

For comparison, BFS with an **adjacency list** and a suitable queue can run in O(V + E) time. The graph representation matters when evaluating performance, especially for large, sparse graphs.

## Real-World Connections

Graph traversal concepts are useful in many areas:

- **Navigation and route planning:** model locations and connections between them.
- **Social networks:** explore relationships and paths between users.
- **Computer networks:** represent devices and their connections.
- **Cybersecurity and fraud analysis:** explore relationships among accounts, devices, and transactions.
- **Robotics:** represent possible locations and movements when planning a route.

The common idea is that a graph stores relationships and a traversal algorithm systematically explores them.

## Learning Objectives

By exploring this project, you can practice:

- Understanding vertices and edges.
- Representing graph connections with an adjacency matrix.
- Using a queue to manage BFS exploration.
- Tracking visited nodes during graph traversal.
- Finding a shortest path by number of edges in an unweighted graph.
- Connecting data-structure theory to a working C++ program.

## Video Demonstration

The accompanying video walks through the program menu and demonstrates adding edges, displaying the adjacency matrix, and finding a shortest path with BFS.

**YouTube video:** https://youtu.be/ECBQ8dTK-So?si=OPB2oaMwEN0gFiqy

## LinkedIn


## References

- Stanford University, Computer Science Education Library — Queue: https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Queue.html
- University of Washington — Graph Search: https://courses.cs.washington.edu/courses/cse417/25au/readings/bfsdfs.html
- University of Illinois Urbana-Champaign — BFS & DFS: https://courses.grainger.illinois.edu/cs225/sp2021/resources/bfs-dfs/
