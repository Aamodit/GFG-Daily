class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1), suffMin(n);
        
        // Step 1: Build suffix minimum array
        suffMin[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffMin[i] = min(arr[i], suffMin[i+1]);
        }

        // Step 2: For each index, binary search farthest j
        for(int i = 0; i < n-1; i++) {
            if(suffMin[i+1] >= arr[i]) {
                ans[i] = -1; // no smaller element exists
                continue;
            }

            int low = i+1, high = n-1, res = -1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(suffMin[mid] < arr[i]) {
                    res = mid;      // candidate
                    low = mid + 1;  // go farther right
                } else {
                    high = mid - 1;
                }
            }
            ans[i] = res;
        }
        
        return ans;
    }
};
