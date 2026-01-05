class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int currXor = 0;

        // XOR of first window
        for (int i = 0; i < k; i++) {
            currXor ^= arr[i];
        }

        int maxXor = currXor;

        // Slide the window
        for (int i = k; i < n; i++) {
            currXor ^= arr[i - k]; // remove outgoing element
            currXor ^= arr[i];     // add incoming element
            maxXor = max(maxXor, currXor);
        }

        return maxXor;
    }
};
