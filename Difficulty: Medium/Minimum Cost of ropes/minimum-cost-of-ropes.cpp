class Solution {
  public:
    virtual int minCost(vector<int>& arr) {
      priority_queue<int, vector<int>, greater<int>> minH;
      for(int &x: arr)
        minH.push(x);
      
      int ans = 0;
      
      while((minH.size()) > 1){
          int one = minH.top();
          minH.pop();
          int two = minH.top();
          minH.pop();
          
          ans += (one + two);
          minH.push((one + two));
      }
          
      return ans;
    }
};