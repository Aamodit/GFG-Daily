class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int n = pat.size(), m = tar.size();
        int i = n-1, j = m-1;
        while(j >= 0 && i >= 0)
        {
            int cnt = 0;
            while(i >= 0 && (pat[i] != tar[j] || (cnt%2 == 1)))
            {
                i--;
                cnt++;
            }
            if(pat[i] == tar[j] && (cnt%2 == 0))
            {
               j--;
               i--; 
            }
            else
            {
                return 0;
            }
            
        }
        return j == -1;
    }
};