class Solution {
	public:
	vector<int> prevSmaller(vector<int>& arr) {
		int n = arr.size();
		stack<int>s;
		vector<int> ans(n, -1);
		for (int i = 0; i<n; i++)
			{
			while (!s.empty() && arr[i]<=s.top())
				{
				s.pop();
			}
			if (s.empty())
				{
				ans[i] = -1;
			}
			else
				{
				ans[i] = s.top();
			}
			s.push(arr[i]);
		}
		return ans;
	}
};
