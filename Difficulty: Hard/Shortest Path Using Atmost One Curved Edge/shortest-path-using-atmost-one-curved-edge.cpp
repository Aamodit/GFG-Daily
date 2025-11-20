class Solution {
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        
        const long long INF = 1e18;
        int N = 2 * V;
        vector<vector<pair<int,int>>> adj(N);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w1 = e[2], w2 = e[3];

            int u0 = u, v0 = v;
            int u1 = u + V, v1 = v + V;

            adj[u0].push_back({v0, w1});
            adj[v0].push_back({u0, w1});
            adj[u1].push_back({v1, w1});
            adj[v1].push_back({u1, w1});

            adj[u0].push_back({v1, w2});
            adj[v0].push_back({u1, w2});
        }

        vector<long long> dist(N, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[a] = 0;
        pq.push({0, a});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                long long w = it.second;
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        long long ans = min(dist[b], dist[b + V]);
        return (ans >= INF ? -1 : (int)ans);
    }
};
