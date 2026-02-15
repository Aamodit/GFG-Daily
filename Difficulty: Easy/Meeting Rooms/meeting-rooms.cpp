class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin() , arr.end() , [](auto & a , auto & b){
                return b[1] > a[1]; 
        });
        bool flag = true; // it mean we assume person attend all meeting
        for(int i = 0 ; i< arr.size() -1  ; i++) {
            if(arr[i][1] > arr[i+1][0]) flag = false ;
        }
        return flag ;
    }
};