//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
        // Step 1: Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> graph;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!( (u == c && v == d) || (u == d && v == c) )) { 
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        // Step 2: Perform DFS to check if 'd' is reachable from 'c'
        vector<bool> visited(V, false);
        
        // Helper function for DFS
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        // Start DFS from node 'c'
        dfs(c);

        // Step 3: If 'd' is not visited, then it was not reachable after removing the edge (c, d)
        return !visited[d];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends