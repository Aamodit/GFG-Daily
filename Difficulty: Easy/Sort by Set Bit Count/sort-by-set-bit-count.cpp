class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            return countA > countB; // descending order
        });
        
        return arr;
    }
};