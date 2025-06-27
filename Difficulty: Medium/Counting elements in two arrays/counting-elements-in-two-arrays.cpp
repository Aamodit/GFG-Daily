class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
       int n=a.size();
       int m=b.size();
       vector<int>ans(n,0);
       vector<int>temp((1e5)+1,0);
       for(int i=0;i<m;i++){
           temp[b[i]]++;
       }
       for(int i=1;i<=1e5;i++){
           temp[i]=temp[i]+temp[i-1];
       }
       //kis number se chhota kitne number hai b mein
       for(int i=0;i<n;i++){
           ans[i]=temp[a[i]];
       }
       return ans;
    }
};