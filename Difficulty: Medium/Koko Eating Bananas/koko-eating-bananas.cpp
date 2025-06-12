class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n =arr.size();
        
        int l=1,h= *max_element(arr.begin() , arr.end());
        
        int ans = 1 ; 
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(isvalid(arr , k , mid )){
                ans = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
            
        }
        
        return ans;
    }
    
private:
    
    bool isvalid(vector<int> &arr , int k , int mid){
        int hours = 0 ;
        
        for(int i=0;i<arr.size();i++){
            hours += arr[i]/mid;
            if(arr[i]%mid){
                hours++;
            }
        }
        
        return hours<=k;
    }
};