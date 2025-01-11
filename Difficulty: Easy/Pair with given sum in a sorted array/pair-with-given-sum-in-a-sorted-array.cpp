//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
   public:
    int countPairs(vector<int> &arr, int target) {
        int i=0;
        int j= arr.size()-1;
        int ans= 0;
        while(i<j){
            int sum= arr[i]+ arr[j];
            if(sum<target){
                i++;
            }
            else if(sum> target){
                j--;
            }
            else{
                int val1= arr[i];
                int val2= arr[j];
                int count1=0;
                int count2=0;
                while(i<=j && arr[i]== val1){
                    i++;
                    count1++;
                    
                }
                while(i<=j && arr[j]== val2){
                    j--;
                    count2++;
                }
                if(val1== val2){
                    ans= ans+ (count1*(count1-1))/2;
                }
                else{
                    ans= ans+(count1* count2);
                }
            }
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
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends