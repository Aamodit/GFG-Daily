class Solution {
public:
    
    int digitSum(long long x) {
        int s = 0;
        while(x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
    
    int getCount(int n, int d) {
        long long low = 1, high = n;
        long long ans = n + 1;  // first valid
        
        while(low <= high) {
            long long mid = (low + high) / 2;
            
            if(mid - digitSum(mid) >= d) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        if(ans > n) return 0;
        return n - ans + 1;
    }
};
