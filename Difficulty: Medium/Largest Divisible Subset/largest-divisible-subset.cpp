class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> dp(n, 1);        // dp[i]: length of largest subset ending at i
        vector<int> parent(n, -1);   // parent[i]: previous index in subset

        int maxLen = 1, maxIndex = 0;

        // Loop from end to start for lexicographically greatest
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] % arr[i] == 0 && dp[j] + 1 >= dp[i]) {
                    if (dp[j] + 1 > dp[i] || (dp[j] + 1 == dp[i] && arr[j] > arr[parent[i]])) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] >= maxLen) {
                if (dp[i] > maxLen || arr[i] > arr[maxIndex]) {
                    maxLen = dp[i];
                    maxIndex = i;
                }
            }
        }

        // Reconstruct the subset
        vector<int> res;
        int curr = maxIndex;
        while (curr != -1) {
            res.push_back(arr[curr]);
            curr = parent[curr];
        }

        sort(res.begin(), res.end()); // required by problem
        return res;
    }
};
