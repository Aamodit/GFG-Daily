class Solution {
  public:
    int maxIndexDifference(string &s) {
        
        int n = s.length(), i = 0;
        while(i < n && s[i] != 'a') i ++;
        
        if(i == n)  return -1;
        
        vector<int> idx(26, -1);
        idx[0] = i;
        
        char toSearch = 'b';
        while(i < n) {
            
            if(s[i] == toSearch) {
                
                idx[toSearch - 'a'] = i;
                toSearch += 1;
            }
            else if(idx[s[i] - 'a'] != -1 && s[i] != 'a')  idx[s[i] - 'a'] = i;
            
            i ++;
        }
        
        int maxx = 0;
        for(int i = 1; i < 26 && idx[i] != -1; i ++) maxx = max(idx[i] - idx[0], maxx);
        
        return maxx;
    }
};
