class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long maxSum = 0, minSum = 0;

        // ---------- SUM OF SUBARRAY MAXIMUMS ----------
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            maxSum += (long long)arr[i] * left[i] * right[i];

        // ---------- SUM OF SUBARRAY MINIMUMS ----------
        while (!st.empty()) st.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            minSum += (long long)arr[i] * left[i] * right[i];

        return (int)(maxSum - minSum);
    }
};