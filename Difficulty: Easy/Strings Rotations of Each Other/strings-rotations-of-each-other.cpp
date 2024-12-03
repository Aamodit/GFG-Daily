//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {    
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1.length()!=s2.length())return false;
        int i=0,j=0,count=0,flag=0;
        while(i<s1.length()){
            if(j>=s2.length())j=j%s2.length();
            if(s1[i]!=s2[j])j++;
            if(s1[i]==s2[j]){i++;j++;}
            count++;
            if(count>=2*s1.length()){flag=1;break;}
        }
        return flag==0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends