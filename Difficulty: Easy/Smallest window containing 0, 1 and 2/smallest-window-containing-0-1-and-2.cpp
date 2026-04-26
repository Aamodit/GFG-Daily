class Solution {
  public:
    int smallestSubstring(string s) {
        map<char,int> mp;
        int n= s.size();
        int l =0,r =0;
        int leni = INT_MAX;
        while(l<n && r < n) {
            mp[s[r]]++;
            
            while (mp['0'] && mp['1'] && mp['2']) {
                leni = min(leni,r-l+1);
                mp[s[l]]--;
                
                l++;   
            }
            r++;
            
        }
        if (leni == INT_MAX) return -1;
        return leni;
        
    }
};
