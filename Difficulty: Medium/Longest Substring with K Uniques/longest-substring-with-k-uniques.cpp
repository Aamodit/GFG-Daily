class Solution {
  public:
   int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mp;
        int n = s.size();
        int ans = -1, j = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            if(mp.size() > k){
                mp[s[j]]--;
                if(mp[s[j]] == 0)   mp.erase(s[j]);
                j++;
            }
            if(mp.size() == k)  
                ans = max(ans, i - j + 1);
        }
        return ans;
    }
};