class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        int op = 0;
        priority_queue<double> pq;
        double sum = 0;
        
        for (int& val : arr) {
            sum += (val* 1.0);
            pq.push(val * 1.0);
        }
        double half = sum / 2;
        
        while (half < sum) {
            double ele = pq.top() / 2;
            pq.pop();
            sum -= ele;
            op++;
            pq.push(ele);
        }
        
        return op;
    }
};