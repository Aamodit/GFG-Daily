class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int i=0, j=0, k=0 ;
        int res = INT_MAX ;
        string str ;
        
        while(j < s1.length() && k < s2.length())
        {
            if(s1[j] == s2[k])  k++ ;  // goal: try to match the whole s2 as a subsequence.
            
            // When k reaches the end of s2, it means s2 has been found in s1[0...j].
            // Now, to minimize the substring, we move backward from j to find the smallest valid window.
            if(k == s2.length())
            {
                i = j ;
                k = s2.length() - 1 ;
                
                while(i >= 0 && k >= 0)
                {
                    if(s1[i] == s2[k]) k-- ;  // Move backward until all characters of s2 are matched again.
                    i-- ;   
                }
                // When done, i+1 is the start of the minimum window ending at j.
                i++ ;
                
                // Compare current window length (j - i + 1) with best result.
                // If smaller, update res and store the substring.
                if(res > j-i+1)
                {
                    res = j-i+1 ;
                    str = s1.substr(i, j-i+1) ;
                }
                
                // Reset k to search for s2 again.
                // Move j to just after the new starting position, so we don’t miss overlapping windows.
                k=0 ;
                j = i+1 ;
            }
            
            j++ ;  // Keep moving j forward until the end.
        }
        return str ;
    }
};