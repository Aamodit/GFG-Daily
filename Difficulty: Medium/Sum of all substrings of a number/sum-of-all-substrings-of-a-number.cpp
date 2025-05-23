class Solution {
public:
    long long sumSubstrings(string s) {
        int n = s.size();
        long long prev = s[0] - '0';
        long long ans = prev;

        for (int i = 1; i < n; i++) {
            long long curr = prev * 10 + (s[i] - '0') * (i + 1);
            ans += curr;
            prev = curr;
        }

        return ans;
    }
};