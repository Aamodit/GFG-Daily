class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        int l = 0;
        int n = arr.size();
        int sum = 0;

        for(int i = 0; i < n - 1; i++) {
            if(arr[i] < arr[i + 1]) {
                continue;
            } else {
                int m = i - l + 1;
                if(m >= 2) {
                    sum += (m * (m - 1)) / 2;
                }
                l = i + 1;  
            }
        }

    
        int m = n - l;
        if(m >= 2) {
            sum += (m * (m - 1)) / 2;
        }

        return sum;
    }
};