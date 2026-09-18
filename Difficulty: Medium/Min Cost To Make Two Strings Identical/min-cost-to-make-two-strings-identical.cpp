class Solution {
  private:
    int lcs(string &x, string &y){
        int m = x.size();
        int n = y.size();

        vector<int> curr(n+1, 0);
        vector<int> prev(n+1, 0);


        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(x[i-1] == y[j-1])
                    curr[j] = 1+prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return prev[n];
    }
  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int len1 = x.size();
        int len2 = y.size();
        int len = lcs(x, y);

        return (len1-len)*costX+(len2-len)*costY;
    }
};
