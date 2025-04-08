//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<bool>& visited,
             vector<int>& disc, vector<int>& low, vector<bool>& isAP, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, adj, visited, disc, low, isAP, time);
                low[u] = min(low[u], low[v]);

                // u is an articulation point in following case
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else if (v != parent) {
                // Update low[u] for back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Special case: if u is root and has more than one child
        if (parent == -1 && children > 1)
            isAP[u] = true;
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> isAP(V, false);
        int time = 0;

        // Call DFS for each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, disc, low, isAP, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};
        sort(result.begin(), result.end());
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends