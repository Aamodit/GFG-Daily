class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int x = 9 * pow(10, n - 1);
        int s = arr.size();
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) s--;
        }
        int a = 10 - arr.size();
        int y = (9 - s) * pow(a, max(0, n - 1));
        return x - y;
    }
};
