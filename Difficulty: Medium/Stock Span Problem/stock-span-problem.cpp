class Solution {
	public:
	vector<int> calculateSpan(vector<int>& arr) {
		// code here
		stack<int>s;
		int n = arr.size();
		vector<int>ans(n, 1);
		
		for (int i = 0; i<n; i++) {
			while (!s.empty() && arr[i]>=arr[s.top()]) {
				s.pop();
			}
			if (!s.empty())
				ans[i] = i - s.top();
				else  ans[i] = i +1;
			s.push(i);
		}
		return ans;
	}
};
