class Solution {
  public:
    virtual vector<int> topKFreq(vector<int> &arr, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      unordered_map<int, int> freq;
      for(auto &x: arr)
        freq[x]++;
      
      for(auto &z: freq){
          pq.push({z.second, z.first});
          if(pq.size() > k)
            pq.pop();
      }
      
      vector<int> ans;
      while(!pq.empty()){
          ans.push_back(pq.top().second);
          pq.pop();
          
      }
      
      reverse(ans.begin(), ans.end());
      return ans;
    }
};