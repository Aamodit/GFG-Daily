//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[V];
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w)); // since the graph is undirected
        }

        // Step 2: Distance array initialized to INF, except src = 0
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 3: Min heap {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
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
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends