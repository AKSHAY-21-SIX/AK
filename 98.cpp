void dfs(int node , int parent, vector<int> &vis, vector<int> adj[],int tin[],int low[],int timer,
vector<vector<int>> &bridges)
{
   vis[node]=1;
   tin[node]=low[node]=timer;
   timer++;
 for(auto it: adj[node])
{
   if(it == parent) continue;
   if(vis[it]==0)
{
   dfs(it, node,vis,adj,tin,low,timer,bridges);
   low[node]= min(low[node],low[it]);
if(low[it] > tin[node])
{

    bridges.push_back({it,node});
}
   }  
     else 
    {
      low[node] = min(low[node], low[it]);
    }
   }
 }
vector<vector<int>> findBridges(vector<vector<int>> &edges, 
int v, int e) 
{

    vector<int> adj[v];
  for(auto it: edges)
{
  adj[it[0]].push_back(it[1]);
  adj[it[1]].push_back(it[0]);
}
 vector<int> vis(v,0);
  int tin[v];
  int low[v];
  int timer=0;
 vector<vector<int>>bridges;
    dfs(0,-1,vis,adj,tin,low,timer,bridges);
 return bridges;

}