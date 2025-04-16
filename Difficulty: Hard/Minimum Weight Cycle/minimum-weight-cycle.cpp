//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(V);

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int minCycle = INF;

        // Try each edge as the one we remove to find alternative path
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            // Dijkstra from u to v excluding edge (u-v)
            vector<int> dist(V, INF);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[u] = 0;
            pq.push({0, u});

            while (!pq.empty()) {
                pair<int, int> p = pq.top(); pq.pop();
                int d = p.first;
                int node = p.second;

                if (d > dist[node]) continue;

                for (int i = 0; i < adj[node].size(); ++i) {
                    int nbr = adj[node][i].first;
                    int wt = adj[node][i].second;

                    // Skip the edge (u, v)
                    if ((node == u && nbr == v && wt == w) || (node == v && nbr == u && wt == w))
                        continue;

                    if (dist[nbr] > dist[node] + wt) {
                        dist[nbr] = dist[node] + wt;
                        pq.push({dist[nbr], nbr});
                    }
                }
            }

            if (dist[v] < INF) {
                minCycle = min(minCycle, dist[v] + w);
            }
        }

        return (minCycle == INF) ? -1 : minCycle;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends