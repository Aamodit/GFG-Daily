/*simple traversal approach using two pointer*/
class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int l = 0, r = height.size()-1, res = 0;
        
        while (l < (r-1)) {
            res = max(res, min(height[l], height[r])*(r -l -1));
            
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return res;
    }
};