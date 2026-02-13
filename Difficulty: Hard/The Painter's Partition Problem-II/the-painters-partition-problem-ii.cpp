class Solution {
    bool canAllBoardsBePainted(int maxTime, int k, vector<int> &arr){
        int painters = 1, curTime = arr[0];
        for(int i=1;i<arr.size();i++){
            if(curTime+arr[i]<=maxTime){
                curTime +=arr[i];
            }
            else{
                painters++;
                curTime = arr[i];
            }
            if(painters>k)
                return false;
        }
        return painters<=k; //true
    }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low<=high){
            int mid = low + (high - low)/2;
            
            if(canAllBoardsBePainted(mid, k, arr)){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return low;
    }
};