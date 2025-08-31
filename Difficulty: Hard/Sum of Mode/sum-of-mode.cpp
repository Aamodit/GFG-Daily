class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return 0;

        unordered_map<int,int> freq;              // element -> freq
        map<int,set<int>> freqMap;                // freq -> {elements}
        int sum = 0;

        auto add = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = oldFreq + 1;
            freq[x] = newFreq;

            if (oldFreq > 0) {
                freqMap[oldFreq].erase(x);
                if (freqMap[oldFreq].empty()) freqMap.erase(oldFreq);
            }
            freqMap[newFreq].insert(x);
        };

        auto remove = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = oldFreq - 1;

            freqMap[oldFreq].erase(x);
            if (freqMap[oldFreq].empty()) freqMap.erase(oldFreq);

            if (newFreq > 0) {
                freq[x] = newFreq;
                freqMap[newFreq].insert(x);
            } else {
                freq.erase(x);
            }
        };

        // first window
        for (int i = 0; i < k; i++) {
            add(arr[i]);
        }
        sum += *freqMap.rbegin()->second.begin();

        // sliding window
        for (int i = k; i < n; i++) {
            remove(arr[i-k]);
            add(arr[i]);
            sum += *freqMap.rbegin()->second.begin();
        }

        return sum;
    }
};
