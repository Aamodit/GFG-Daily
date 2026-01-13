class Solution {
  public:
    virtual int catchThieves(vector<char> &arr, int k){
      int i=0, j=0, n=arr.size();
      int ans=0;
      
      while(i<n && j<n){
        if(arr[j] == 'T') { j++; continue; }
        if(arr[i] == 'P') { i++; continue; }
        
        if(arr[j]=='P' && arr[i]=='T'){
          if(abs(i-j) <= k){
            ans++; i++; j++;      
          }
          else if(i>j)
            j++;
          else
            i++;
        }
        
      }
      
      return ans;
    }
};