#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void DFSUtil(int v, vector<bool>& visited, int level) {
        visited[v] = true;
        cout << v << " level " << level << " " << endl;

        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited, level+1);
            }
        }
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        cout << "Depth First Search (DFS) starting from vertex " << v << ":\n";
        DFSUtil(v, visited, 0);
        cout << "\n";
    }

    void BFS(int v) {
        vector<bool> visited(V, false);
        queue<pair<int, int>> q;

        visited[v] = true;
        q.push({v, 0});

        cout << "Breadth First Search (BFS) starting from vertex " << v << ":\n";

        while (!q.empty()) {
            pair<int, int> node = q.front();
            int vertex = node.first;
            int level = node.second;
            cout << vertex << " (Level " << level << ") ";
            q.pop();

            for (int i : adj[vertex]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push({i, level + 1});
                }
            }
        }
        cout << "\n";
    }
};

int main() {
    int V = 6; 

    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // g.DFS(1);
    g.BFS(3);

    return 0;
}