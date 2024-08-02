#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int d){
    map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;
    while(!q.empty()){
            int front= q.front();
            q.pop();
            for(auto j:adj[front]){
                if(!vis[j]){
                    vis[j] = true;
                    parent[j] = front;
                    q.push(j);
                }
            }
        }
    vector<int> ans;
    while(d!=s){
        ans.push_back(d);
        d = parent[d];
    }
    ans.push_back(d);
    reverse(ans.begin(),ans.end());
    return ans;
}