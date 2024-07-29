class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
        stack<int> s;
        s.push(node);
        
        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!vis[curr]) {
                vis[curr] = 1;
                pathVis[curr] = 1;
                s.push(curr);
                for (int neighbor : adj[curr]) {
                    if (!vis[neighbor]) {
                        s.push(neighbor);
                    } else if (pathVis[neighbor]) {
                        return true;
                    }
                }
            } else {
                pathVis[curr] = 0;
            }
        }
        return false;
    }
};