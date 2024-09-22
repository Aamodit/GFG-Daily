//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size(),a=-1,b=-1,val;
        for(int i=0;i<n;i++) {
            val=(arr[i]-1)%n;
            arr[val]+=n;
        }
        for(int i=0;i<n;i++){
            val=(arr[i]-1)/n;
            if(val>=2)  a=i+1;
            else if(val==0) b=i+1;
        }
        return {a,b};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends