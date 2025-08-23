class Solution {
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n=arr.size();
        
        if((m*k)>n) return -1; 
        else
        {
            sort(arr.begin(),arr.end());
            return(arr[m*k-1]);
        }
    }
};