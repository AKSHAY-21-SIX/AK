#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
using namespace std;
void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<pair<int, int>>>& adj) {
    visited[v] = true;
    for (const auto& neighbor : adj[v]) {
        int u = neighbor.first;
        if (!visited[u]) {
            topologicalSortUtil(u, visited, Stack, adj);
        }
    }
    Stack.push(v);
}
vector<int> shortestPathDAG(int V, const vector<vector<pair<int, int>>>& adj, int source) {
    stack<int> Stack;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }
    vector<int> dist(V, numeric_limits<int>::max());
    dist[source] = 0;
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();
        if (dist[u] != numeric_limits<int>::max()) {
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
             }
       }
    }
    return dist;
}
int main() {
    int V = 6; 
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 3});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 6});
    adj[2].push_back({3, 7});
    adj[2].push_back({4, 4});
    adj[4].push_back({3, 2});
    adj[4].push_back({5, 6});
    adj[3].push_back({5, 1});
    adj[5].push_back({3, 4});
    int source = 1;
    vector<int> dist = shortestPathDAG(V, adj, source);
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Vertex " << i << " is not reachable from source\n";
        } else {
            cout << "Vertex " << i << " has distance " << dist[i] << "\n";
        }
    }
    return 0;
}