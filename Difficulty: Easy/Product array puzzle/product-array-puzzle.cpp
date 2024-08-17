//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
         vector<long long int>ans;
        long long int sum=1;
        int temp=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                temp++;
                if(temp>1)break;
            }
        }
        for(int i=0;i<n;i++)if(nums[i]!=0)sum*=nums[i];
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(temp>=1)ans.push_back(0);
                else{
                    ans.push_back(sum/(long long int)nums[i]);
                }
            }
            else{
                if(temp>1)ans.push_back(0);
                else ans.push_back(sum);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends