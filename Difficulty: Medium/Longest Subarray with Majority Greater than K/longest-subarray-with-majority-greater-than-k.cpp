class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixIndex;
        int prefixSum = 0;
        int maxLength = 0;
        
        for (int i = 0; i < n; ++i) {
            // Transform the array
            if (arr[i] > k) {
                prefixSum += 1;
            } else {
                prefixSum -= 1;
            }
            
            // If the prefixSum is positive, whole subarray [0...i] is valid
            if (prefixSum > 0) {
                maxLength = i + 1;
            }
            else {
                // We want to find earliest index with prefixSum - 1
                if (prefixIndex.find(prefixSum - 1) != prefixIndex.end()) {
                    maxLength = max(maxLength, i - prefixIndex[prefixSum - 1]);
                }
            }
            
            // Store first occurrence of this prefixSum
            if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
                prefixIndex[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};
