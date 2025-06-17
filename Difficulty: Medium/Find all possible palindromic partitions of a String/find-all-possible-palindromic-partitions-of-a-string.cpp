class Solution {
    vector<vector<string>> ans;
  public:
    vector<vector<string>> palinParts(string &s) {
        int n = s.length();
        vector<string> curr;
        int idx = 0;
        travel(s, n, idx, curr);
        return ans;
    }
    
    void travel(string &s, int n, int idx, vector<string> &curr){
        if(idx == n){
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < n; i++){
            if(isPalin(s, idx, i)){
                curr.push_back(s.substr(idx, i - idx + 1));
                travel(s, n, i + 1, curr);
                curr.pop_back();
            }
        }
    }
    
    bool isPalin(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};