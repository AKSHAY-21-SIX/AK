#include <bits/stdc++.h> 
void topologicalSortDFS(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s, int node){
    visited[node] = 1;
 for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topologicalSortDFS(adj, visited, s, neighbour);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v+1);
for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> visited(v, false);
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topologicalSortDFS(adj, visited, s, i);
        }
    }
    vector<int> ans;
       while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}