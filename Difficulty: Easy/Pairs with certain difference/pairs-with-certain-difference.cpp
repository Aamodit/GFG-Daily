class Solution {
public:
    int sumDiffPairs(vector<int>& arr, int k) {
        
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int sum = 0;

        for(int i = n - 1; i > 0; i--){
            // If pair possible
            if(arr[i]-arr[i-1] < k) {
                sum += arr[i] + arr[i-1];
                // Skip both used elements
                i--;
            }
        }

        return sum;
    }
};