class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];

        long long total = prefix[n];
        long long res = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long left = prefix[i];  // coins removed from left side

            int j = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();

            long long right = 0;
            if (j < n) {
                long long coinsToKeep = 1LL * (arr[i] + k) * (n - j);
                right = (prefix[n] - prefix[j]) - coinsToKeep;
            }

            res = min(res, left + right);
        }

        return static_cast<int>(res);
    }
};
