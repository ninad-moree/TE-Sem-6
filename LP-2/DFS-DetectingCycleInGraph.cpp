/*
    Given the root of a Directed graph, The task is to check whether the graph contains a cycle or not. 
*/

#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recursionStack) {
    if (!visited[v]) {
        visited[v] = true;
        recursionStack[v] = true;

        for (int i : adj[v]) {
            if (!visited[i] && isCyclicUtil(i, adj, visited, recursionStack))
                return true;
            else if (recursionStack[i])
                return true;
        }
    }

    recursionStack[v] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<bool> recursionStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (isCyclicUtil(i, adj, visited, recursionStack))
            return true;
    }

    return false;
}

int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges
    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {}; 

    if (isCyclic(adj))
        cout << "The graph contains a cycle." << endl;
    else 
        cout << "The graph does not contain a cycle." << endl;
    

    return 0;
}
