class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                intervals.push_back({L, R});
            }
        }

        // Sort by start
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int idx = 0;
        int currentEnd = 0;

        while (currentEnd < n) {
            int farthest = currentEnd;

            // Extend coverage as far as possible
            while (idx < intervals.size() && intervals[idx].first <= currentEnd) {
                farthest = max(farthest, intervals[idx].second + 1);
                idx++;
            }

            // No progress → impossible
            if (farthest == currentEnd) {
                return -1;
            }

            count++;
            currentEnd = farthest;
        }

        return count;
    }
};
