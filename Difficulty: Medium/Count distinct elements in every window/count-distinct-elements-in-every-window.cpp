class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int>result;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[arr[j]]++;
            if(i<=j&&j-i+1>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            if(j-i+1==k)result.push_back(mp.size());
            j++;
        }
        return result;
    }
};