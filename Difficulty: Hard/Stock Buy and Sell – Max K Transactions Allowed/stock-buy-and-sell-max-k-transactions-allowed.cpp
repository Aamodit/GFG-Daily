//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int k) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        // Handle the unlimited transactions case
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        // Space-optimized DP solution
        std::vector<std::vector<int>> dp(2, std::vector<int>(n, 0));

        for (int t = 1; t <= k; ++t) {
            int maxDiff = -prices[0];
            for (int i = 1; i < n; ++i) {
                dp[1][i] = std::max(dp[1][i - 1], prices[i] + maxDiff);
                maxDiff = std::max(maxDiff, dp[0][i] - prices[i]);
            }
            dp[0] = dp[1];  // Copy current row to previous row
        }

        return dp[1][n - 1];
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends