//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
         int t= abs(e);
        double ans=1;
        while(t>0)
        {
            if(t%2==1)
            {
                //the power is odd
                ans=ans*b;
                t=t-1;
            }
            else
            {
                b=b*b; //the value inside the brackets squares itself
                t=t/2;
            }
        }
        
        if(e<0)
        {
            ans = 1.0/ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends