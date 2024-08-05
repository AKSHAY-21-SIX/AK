#include <bits/stdc++.h> 

void topo(vector<vector< pair< int, int> > > &adj, int sv, int v, vector<int> &visit, stack<int> &s){
    visit[sv] = 1;
    for(auto i : adj[sv]){
        if(visit[i.first] == 0)
            topo(adj, i.first, v, visit, s);
    }
    s.push(sv);
}

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<vector< pair< int, int> > > adj;
    for(int i = 0; i <= n; i++){
        adj.push_back({{}});
    }
    
    for(int i = 0; i < edges.size(); i++){
        vector<pair<int,int> > v;
        pair<int, int> p;
        p.first = edges[i][1];
        p.second = edges[i][2];         
        adj[edges[i][0]].push_back(p);
    }
    stack<int> s;
    vector<int> visit(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(visit[i] == 0)
            topo(adj, i, n, visit, s);
    }
    
    vector<int> dist(n + 1, 1000000000);
    dist[src] = 0; 
    while(!s.empty()){
        int k = s.top();
        s.pop();
        if(dist[k] != 1000000000){
            for(auto i: adj[k]){
                dist[i.first] = min(dist[i.first], dist[k] + i.second); 
            }
        }
    }
    return dist[dest];
    
}