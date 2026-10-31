
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// Campus locations
string place[8] = {
    "Main Gate",
    "Library",
    "Block 1",
    "Block 2",
    "Cafeteria",
    "Auditorium",
    "Parking",
    "Lab"
};

int n = 8;

// Graph using adjacency list
vector<int> graph[8];

// Function to add paths
void addEdge(int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

// Show all locations
void showLocations() {
    cout << "\nCampus Locations:\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << place[i] << endl;
    }
}

// Display adjacency list
void showList() {
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < n; i++) {
        cout << place[i] << " : ";

        for (int j = 0; j < graph[i].size(); j++) {
            cout << place[graph[i][j]] << " ";
        }

        cout << endl;
    }
}

// Display adjacency matrix
void showMatrix() {
    int matrix[8][8] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            matrix[i][graph[i][j]] = 1;
        }
    }

    cout << "\nAdjacency Matrix:\n";

    cout << "   ";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "  ";

        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

// BFS to find shortest path
void BFS(int start, int end) {

    bool visited[8] = {false};
    int parent[8];

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {

            int next = graph[current][i];

            if (!visited[next]) {
                visited[next] = true;
                parent[next] = current;
                q.push(next);
            }
        }
    }

    if (!visited[end]) {
        cout << "\nNo route available between these locations.\n";
        return;
    }

    vector<int> path;

    int temp = end;

    while (temp != -1) {
        path.push_back(temp);
        temp = parent[temp];
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest Route:\n";

    for (int i = 0; i < path.size(); i++) {
        cout << place[path[i]];

        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }

    cout << "\nTotal edges: " << path.size() - 1 << endl;
}

// DFS function
void DFS(int start, bool visited[]) {

    visited[start] = true;

    cout << place[start] << endl;

    for (int i = 0; i < graph[start].size(); i++) {

        int next = graph[start][i];

        if (!visited[next]) {
            DFS(next, visited);
        }
    }
}

// Find reachable and disconnected locations
void reachable(int start) {

    bool visited[8] = {false};

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {

            int next = graph[current][i];

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << "\nReachable Locations:\n";

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            cout << place[i] << endl;
        }
    }

    cout << "\nDisconnected Locations:\n";

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << place[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No disconnected locations.\n";
    }
}

// Sample test cases
void testCases() {

    cout << "\nTest Case 1: Main Gate to Library\n";
    BFS(0, 1);

    cout << "\nTest Case 2: Main Gate to Lab\n";
    BFS(0, 7);

    cout << "\nTest Case 3: Main Gate to Auditorium\n";
    BFS(0, 5);
}

int main() {

    // Adding paths between locations
    addEdge(0, 1);
    addEdge(0, 6);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 7);

    int choice, start, end;

    do {

        cout << "\n================================\n";
        cout << "       CAMPUS ROUTE FINDER\n";
        cout << "================================\n";

        cout << "1. Show Locations\n";
        cout << "2. Show Adjacency List\n";
        cout << "3. Show Adjacency Matrix\n";
        cout << "4. Find Shortest Route (BFS)\n";
        cout << "5. Show DFS Traversal\n";
        cout << "6. Show Reachable Locations\n";
        cout << "7. Run Test Cases\n";
        cout << "8. Show Complexity\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                showLocations();
                break;

            case 2:
                showList();
                break;

            case 3:
                showMatrix();
                break;

            case 4:
                showLocations();

                cout << "\nEnter starting location number: ";
                cin >> start;

                cout << "Enter destination location number: ";
                cin >> end;

                if (start >= 1 && start <= 8 &&
                    end >= 1 && end <= 8) {

                    BFS(start - 1, end - 1);

                } else {
                    cout << "Invalid location number!\n";
                }
                break;

            case 5: {
                bool visited[8] = {false};

                showLocations();

                cout << "\nEnter starting location: ";
                cin >> start;

                if (start >= 1 && start <= 8) {
                    cout << "\nDFS Traversal:\n";
                    DFS(start - 1, visited);
                } else {
                    cout << "Invalid location number!\n";
                }
                break;
            }

            case 6:
                showLocations();

                cout << "\nEnter starting location: ";
                cin >> start;

                if (start >= 1 && start <= 8) {
                    reachable(start - 1);
                } else {
                    cout << "Invalid location number!\n";
                }
                break;

            case 7:
                testCases();
                break;

            case 8:
                cout << "\nTime Complexity:\n";
                cout << "BFS: O(V + E)\n";
                cout << "DFS: O(V + E)\n";

                cout << "\nSpace Complexity:\n";
                cout << "BFS: O(V)\n";
                cout << "DFS: O(V)\n";
                cout << "Adjacency List: O(V + E)\n";
                cout << "Adjacency Matrix: O(V * V)\n";
                break;

            case 0:
                cout << "\nThank you!\n";
                break;

            default:
                cout << "\nWrong choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

