class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        set<pair<int, int>> seen;

        // Push the initial (maximum) sum with indices (0, 0)
        maxHeap.push({a[0] + b[0], {0, 0}});
        seen.insert({0, 0});

        vector<int> result;

        while (k-- && !maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            result.push_back(sum);

            // Next index pair: (i+1, j)
            if (i + 1 < n && seen.find({i + 1, j}) == seen.end()) {
                maxHeap.push({a[i + 1] + b[j], {i + 1, j}});
                seen.insert({i + 1, j});
            }

            // Next index pair: (i, j+1)
            if (j + 1 < n && seen.find({i, j + 1}) == seen.end()) {
                maxHeap.push({a[i] + b[j + 1], {i, j + 1}});
                seen.insert({i, j + 1});
            }
        }

        return result;
    }
};
