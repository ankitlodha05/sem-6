#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // for an undirected graph
    }

    void DFS(int start, vector<bool>& visited, vector<int>& component) {
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int v = stk.top();
            stk.pop();

            if (!visited[v]) {
                visited[v] = true;
                component.push_back(v);

                for (int neighbor : adj[v]) {
                    if (!visited[neighbor]) {
                        stk.push(neighbor);
                    }
                }
            }
        }
    }

    void connectedComponents() {
        vector<bool> visited(V, false);

        cout << "Connected Components:\n";
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                vector<int> component;
                DFS(v, visited, component);

                // Print the connected component
                cout << "Connected Component:";
                for (int vertex : component) {
                    cout << " " << vertex;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.connectedComponents();

    return 0;
}
