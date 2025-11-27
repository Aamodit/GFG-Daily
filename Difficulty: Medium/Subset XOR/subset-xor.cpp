class Solution {
public:
    vector<int> subsetXOR(int n) {
        int X = 0;
        for (int i = 1; i <= n; i++) X ^= i;

        int missing = X ^ n;

        vector<int> ans;
        ans.reserve(n);

        // If XOR of full set is already n, take all numbers
        if (missing == 0) {
            for (int i = 1; i <= n; i++) ans.push_back(i);
            return ans;
        }

        // Otherwise skip `missing`
        for (int i = 1; i <= n; i++) {
            if (i != missing) ans.push_back(i);
        }
        return ans;
    }
};
