# Campus Route Finder Using Graphs

## Introduction
Campus Route Finder is a Data Structures and Algorithms (DSA) mini project developed using C++. This project helps users find routes between different locations inside a college campus using Graph Data Structure.

In this project, each campus location is represented as a vertex and the paths between locations are represented as edges.

## Objectives
- To understand Graph Data Structure.
- To implement Breadth First Search (BFS).
- To implement Depth First Search (DFS).
- To find the shortest path between two locations.
- To identify reachable and disconnected locations.
- To understand graph representation using Adjacency List and Adjacency Matrix.

## Technologies Used
- Programming Language: C++
- IDE: Dev-C++
- Data Structure: Graph
- Algorithms: BFS and DFS

## Features
1. Display all campus locations.
2. Display Adjacency List.
3. Display Adjacency Matrix.
4. Find the shortest route using BFS.
5. Perform DFS traversal.
6. Display reachable locations.
7. Identify disconnected locations.
8. Run sample test cases.
9. Display time and space complexity.

## Campus Locations

The project contains 8 campus locations:

1. Main Gate
2. Library
3. Block 1
4. Block 2
5. Cafeteria
6. Auditorium
7. Parking
8. Lab

## Algorithms Used

### 1. Breadth First Search (BFS)
BFS is used to find the shortest path between two campus locations. It uses a queue to visit vertices level by level.

### 2. Depth First Search (DFS)
DFS is used to traverse the graph. It visits a location and then explores its connected locations.

### 3. Graph Representation
The graph is represented using:
- Adjacency List
- Adjacency Matrix

## Sample Test Cases

| Test Case | Source | Destination | Expected Result |
|---|---|---|---|
| 1 | Main Gate | Library | Direct route |
| 2 | Main Gate | Lab | Shortest route |
| 3 | Main Gate | Auditorium | No route available |

## Time and Space Complexity

| Algorithm | Time Complexity |
|---|---|
| BFS | O(V + E) |
| DFS | O(V + E) |

| Representation | Space Complexity |
|---|---|
| Adjacency List | O(V + E) |
| Adjacency Matrix | O(V * V) |

Here, V represents the number of vertices and E represents the number of edges.

## How to Run the Project

1. Download or clone this repository.
2. Open Dev-C++.
3. Open the `main.cpp` file.
4. Click on Compile and Run.
5. Select an option from the menu.
6. Enter the required location numbers.

## Conclusion

This project demonstrates how Graph Data Structure can be used to represent a college campus and find routes between different locations. By using BFS and DFS algorithms, we can find shortest paths, traverse connected locations and identify disconnected locations.

The project helped in understanding the practical implementation of Graphs in C++.

## Author
- Name: Vinita
- Roll Number: 2556515
- Class: CSE B SEM 3
- College: CCE

  
