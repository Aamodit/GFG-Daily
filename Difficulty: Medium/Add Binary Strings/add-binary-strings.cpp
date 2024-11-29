//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
string addBinary(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        int i=n-1,j=m-1;
        int c=0;
        string t="";
        while(i>=0 && j>=0){
            if(s1[i]=='1' && s2[j]=='1'){
                if(c==1){
                    t+='1';
                    c=1;
                }
                else{
                    t+='0';
                    c=1;
                }
            }
            else if(s1[i]=='0' && s2[j]=='1' || s1[i]=='1' && s2[j]=='0' ){
                if(c==1){
                    t+='0';
                    c=1;
                }
                else{
                    t+='1';
                }
            }
            else{
                if(c==1){
                    t+='1';
                    c=0;
                }
                else{
                    t+='0';
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            if(s1[i]=='1'){
                if(c==1){
                    t+='0';
                    c=1;
                }
                else{
                    t+='1';
                }
            }
            else{
                if(c==1){
                    t+='1';
                    c=0;
                }
                else{
                    t+='0';
                }
            }
            i--;
        }
        while(j>=0){
            if(s2[j]=='1'){
                if(c==1){
                    t+='0';
                    c=1;
                }
                else{
                    t+='1';
                }
            }
            else{
                if(c==1){
                    t+='1';
                    c=0;
                }
                else{
                    t+='0';
                }
            }
            j--;
        }
        if(c){
            t+='1';
        }
        
        while(t.back()=='0'){
            t.pop_back();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends