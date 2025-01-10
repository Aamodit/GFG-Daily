//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        
        // for a substring to be distinct its length should be equal
        // to the current window size 
        
        int i=0;
        int max_len=0;
        
        unordered_map<char,int> window;
        
        for(int j=0;j<s.size();j++){
            
            window[s[j]]++;
            
            while(i<j && window.size()<j-i+1){
                window[s[i]]--;
                if(window[s[i]]==0)window.erase(s[i]);
                i++;
            }
            
            max_len=max(max_len,j-i+1);
            
        }
        
        return max_len;
        
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends