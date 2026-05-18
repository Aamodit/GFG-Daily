class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        const int MOD = 1000;

        if (start == end) return 0;

        vector<int> dist(MOD, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int a : arr) {
                int nxt = (node * a) % MOD;

                if (dist[nxt] == -1) {
                    dist[nxt] = dist[node] + 1;

                    if (nxt == end) return dist[nxt];

                    q.push(nxt);
                }
            }
        }

        return -1;
    }
};