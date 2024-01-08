/*
    Find the level of given node in an Undirected Graph
    Given an undirected graph with V vertices and E edges and a node X, 
    The task is to find the level of node X in the undirected graph. 
    If X does not exist in the graph then return -1.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findNodeLevel(int X, vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> level(V, 0); 
    queue<int> q;

    q.push(0); 
    visited[0] = true; 

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                level[i] = level[node] + 1; // Increment level from the current node
                q.push(i);
            }
        }
    }

    if (X >= 0 && X < V)
        return (visited[X]) ? level[X] : -1;
    else 
        return -1;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges 
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {4};
    adj[3] = {};
    adj[4] = {};

    int nodeToFind = 3; 
    int level = findNodeLevel(nodeToFind, adj);

    if (level != -1)
        cout << "Level of node " << nodeToFind << " is: " << level << endl;
    else 
        cout << "Node " << nodeToFind << " does not exist in the graph." << endl;

    return 0;
}
