class Solution
{
private:
    bool cycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited)
    {

        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (parent == it)
                continue;
            if (visited[it])
                return 1;
            if (cycleDetect(it, node, adj, visited))
                return 1;
        }
        return 0;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (cycleDetect(i, -1, adj, visited))
                    return 1;
        }
        return 0;
    }
};