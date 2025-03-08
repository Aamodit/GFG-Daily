//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int helper(string &s,int i,int j){
        int cnt=0;
        if(i==j){
            i--;
            j++;
        }
        while(i>=0 && j<s.length()){
            if(s[i]==s[j]) cnt++;
            else break;
            i--;
            j++;
        }
        return cnt;
    }
    int countPS(string &s) {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=helper(s,i,i);
            if(i+1<n) cnt+=helper(s,i,i+1);
        }
        
        return cnt;
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends