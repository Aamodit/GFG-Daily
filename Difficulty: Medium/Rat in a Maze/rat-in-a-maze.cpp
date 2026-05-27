class Solution {
	public:
	vector<vector<int>> m;
	string path;
	vector<string>ans;
	vector<vector<bool>> v;
	int n;
	
	bool isValid(int r, int c)
	{
		if (!(r >= 0 && c >= 0 && c<n && r<n))
			{
			return false;
		}
		if (!(m[r][c] == 1))
			{
			return false;
		}
		if (v[r][c])
			{
			return false;
		}
		return true;
	}
	
	void solve(int r, int c)
	{
		if (!isValid(r, c))
			{
			return;
		}
		if (r == n - 1 && c == n - 1)
			{
			ans.push_back(path);
			return;
		}
		v[r][c] = true;
		path.push_back('D');
		solve(r + 1, c);
		path.pop_back();
		path.push_back('L');
		solve(r, c - 1);
		path.pop_back();
		path.push_back('R');
		solve(r, c + 1);
		path.pop_back();
		path.push_back('U');
		solve(r - 1, c);
		path.pop_back();
		
		v[r][c] = false;
		return;
	}
	
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		// code here
		m = maze;
		n = m.size();
		v = vector<vector<bool>> (n, vector<bool>(n, false));
		solve(0, 0);
		return ans;
	}
};
