//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int>maxi;
         vector<double> ans;
        priority_queue<int,vector<int>,greater<int>>mini;
        
        for(int i=0;i<arr.size();i++){
            int x = arr[i];
             if(maxi.empty() || x<= maxi.top())
              maxi.push(x);
            else
             mini.push(x);
            
        
            if(mini.size()>maxi.size()+1){
                maxi.push(mini.top());
                mini.pop();
            }else if(maxi.size()>mini.size()+1){
                mini.push(maxi.top());
                maxi.pop();
            }
             
           int n = mini.size();
           int m = maxi.size();
           if(n==m)
           ans.push_back((mini.top()+maxi.top())/2.0);
           else if(n>m)
            ans.push_back(mini.top());
           else
            ans.push_back(maxi.top());
        
           }
         
           return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends