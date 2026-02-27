class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size(), m = arr2.size();
        
        int i = 0;        // start of arr1
        int j = m - 1;    // end of arr2
        
        int bestDiff = INT_MAX;
        vector<int> ans(2);
        
        while (i < n && j >= 0) {
            long long sum = (long long)arr1[i] + arr2[j];
            int diff = abs(sum - x);
            
            if (diff < bestDiff) {
                bestDiff = diff;
                ans = {arr1[i], arr2[j]};
            }
            
            // adjust pointers
            if (sum > x) 
                j--;
            else 
                i++;
        }
        
        return ans;
    }
};