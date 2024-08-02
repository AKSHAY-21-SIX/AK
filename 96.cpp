#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int src) {
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back( make_pair(v,w) );
        adj[v].push_back( make_pair(u,w) );

    }
   set< pair<int,int> > s;
   vector<int> dist(n,INT_MAX);
   dist[src] = 0;
   s.insert( make_pair(0,src)); 
   while(!s.empty()){
       auto top = *(s.begin());
       s.erase(s.begin());
       int topDistance = top.first;
       int topNode = top.second;
       for(auto i : adj[topNode]){
            int v = i.first;
            int w = i.second;
            int d = topDistance + w;
            if(d < dist[v]){
                dist[v] = min(dist[v],d);
                s.insert(make_pair(dist[v], v));
            }
        }
   }
   return dist;
}