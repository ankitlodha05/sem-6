#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class SocialNetwork {
    unordered_map<int, vector<int>> graph; // Adjacency list representation

public:
    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u); // assuming an undirected graph
    }

    vector<int> findPeopleWithinDistance(int startNode, int k) {
        vector<int> result;
        unordered_set<int> visited;

        queue<pair<int, int>> q; // (node, distance) pair

        q.push({startNode, 0});
        visited.insert(startNode);

        while (!q.empty()) {
            int currentNode = q.front().first;
            int currentDistance = q.front().second;
            q.pop();

            if (currentDistance > k) {
                break; // we only want to explore up to 'k' levels
            }

            result.push_back(currentNode);

            for (int neighbor : graph[currentNode]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push({neighbor, currentDistance + 1});
                    visited.insert(neighbor);
                }
            }
        }

        return result;
    }
};

int main() {
    SocialNetwork socialNetwork;

    socialNetwork.addEdge(1, 2);
    
    socialNetwork.addEdge(2, 3);
    socialNetwork.addEdge(2, 4);
    socialNetwork.addEdge(1, 3);
    socialNetwork.addEdge(2, 5);
    socialNetwork.addEdge(3, 6);

    int startNode = 2;
    int distance = 1;

    cout << "People within distance " << distance << " from node " << startNode << " are: ";
    vector<int> result = socialNetwork.findPeopleWithinDistance(startNode, distance);

    for (int person : result) {
        cout << person << " ";
    }

    return 0;
}