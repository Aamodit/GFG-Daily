class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // Get index of largest final element in the array
        int idx = 0;
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            if(arr[i]>arr[idx]){
                idx = i;
            }
        }
        
        vector<int> sol(arr.size(),-1);
        stack<int> st;
        
        // We start iterating just after the largest element in the 
        // circular fashion upto the largest element
        
        for(int i = idx+1;i<=idx+n;i++){
            while((!st.empty()) and (arr[i%n]>arr[st.top()])){
                sol[st.top()] = arr[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        
        return sol;
    }
};