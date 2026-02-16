class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        vector<pair<int,int>> events;
        
        for(auto &it : arr){
            events.push_back({it[0], 1});   // start of interval
            events.push_back({it[1], -1});  // end of interval
        }
        
        // sort by time, if same time -> start (+1) first
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        
        int active = 0, ans = 0;
        
        for(auto &e : events){
            active += e.second;
            ans = max(ans, active);
        }
        
        return ans;
    }
};
