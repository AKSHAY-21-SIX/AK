#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    unordered_map<int, list<int>> adj;

 

    for(int i=0;i<e;i=i+1) adj[edges[i][0]].push_back(edges[i][1]);

    

    vector<int> indegree(v);

 

    for(auto i:adj)

        for(auto j:i.second) indegree[j]++;

 

    queue<int> que;

 

    for(int i=0;i<v;i++)

        if(indegree[i] == 0) que.push(i);

    

    vector<int> sort;

 

    while(!que.empty()){

        sort.push_back(que.front());

 

        for(auto i:adj[que.front()]){

            indegree[i]--;

            if(indegree[i] == 0) que.push(i);

        }

 

        que.pop();

    }

 

    return sort;

}