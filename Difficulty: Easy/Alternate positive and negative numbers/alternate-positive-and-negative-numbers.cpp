//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int>a,b;
        int n= end(arr) - begin(arr);
        
        for(int i=0 ; i < n;i++){
            
            if(arr[i] >= 0){
                a.push_back(arr[i]);//positive
            }
            else{
                b.push_back(arr[i]);//negative
            }
        }
        
        int i=0;
        int j=0;
        
        vector<int>ans;
        
        while(i < a.size() && j < b.size()){
            
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            
            i++;
            j++;
        }
        
        while(i < a.size()){
        ans.push_back(a[i]);
        i++;
        }
        
        while(j < b.size()){
        ans.push_back(b[j]);
        j++;
        }
        
        arr=ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends