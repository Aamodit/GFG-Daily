//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &st, vector<int> &fi) {
        vector<pair<int,int>>vec;
        for(int i=0;i<fi.size();i++){
            vec.push_back({st[i],fi[i]});
        }
        sort(vec.begin(),vec.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second < b.second;
        });
        int ans = 1;
        int prev = vec[0].second;;
        for(int i=1;i<vec.size();i++){
            if(prev < vec[i].first){
                prev = vec[i].second;
                ans++;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends