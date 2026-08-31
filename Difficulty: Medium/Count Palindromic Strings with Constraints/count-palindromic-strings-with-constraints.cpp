
class Solution {
public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007LL;

        long long ans = 0;
        long long perm = 1;  // P(k, 0)

        // r = number of characters in the first half
        for (int r = 1; 2 * r - 1 <= n; r++) {
            // P(k, r)
            perm = (perm * (k - r + 1)) % MOD;

            // Length = 2r - 1
            ans = (ans + perm) % MOD;

            // Length = 2r
            if (2 * r <= n) {
                ans = (ans + perm) % MOD;
            }
        }

        return (int)ans;
    }
};

