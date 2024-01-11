#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isCyclic(vector<vector<int>>& adj) {
    int V = adj.size();

    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            stack<pair<int, int>> stack;
            stack.push({i, -1}); // Pair of node and its parent

            while (!stack.empty()) {
                int currentNode = stack.top().first;
                int parent = stack.top().second;
                stack.pop();

                visited[currentNode] = true;

                for (int neighbor : adj[currentNode]) {
                    if (!visited[neighbor]) {
                        stack.push({neighbor, currentNode});
                    } else if (neighbor != parent) {
                        // If the neighbor is visited and not the parent (back edge), cycle found
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    // vector<vector<int>> adj = { {1, 2}, {2}, {0, 3}, {3} };

    vector<vector<int>> adj = { {1}, {2, 5}, {3}, {4}, {0, 1}, {} };

    // vector<vector<int>> adj = { {1, 2} , {2}, {3, 0}, {} };

    // vector<vector<int>> adj = { {1, 2} , { }, {3}, {1} };

    if (isCyclic(adj)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
