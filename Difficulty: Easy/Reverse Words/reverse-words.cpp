//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int i=0,j=0;
        string ans="";
        while(i<=j && j<str.size()){
            while(str[j]!='.' && j<str.size()){
                j++;
            }
            string s = str.substr(i,j-i);
            if(ans!=""){
            ans = s + "." + ans;
            }else{
                ans = s;
            }
            j++;
            i=j;
        }
        return ans;
    }
}; 

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends