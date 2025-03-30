//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        
        int n = s.length();
        unordered_map<char,int> map;
        
        for(int i=0; i<n; i++){
            map[s[i]] = i;
        }
        int count = 0;
        int i = 0;
        
        while(i < n){
            int last = map[s[i]];
            int j = i;
            
            while(j < last){
                last = max(last,map[s[j]]);
                j++;
            }
            count++;
            i = j+1;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends