class Solution {
public:
    vector<string> findExpr(string &s, int target) {
        vector<string> result;
        string path;
        dfs(s, target, 0, 0, 0, path, result);
        sort(result.begin(), result.end()); // ensure lexicographic order
        return result;
    }

private:
    void dfs(string &s, long long target, int pos, long long eval, long long multed,
             string path, vector<string> &result) {
        if (pos == s.size()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = pos; i < s.size(); i++) {
            // avoid leading zeros
            if (i != pos && s[pos] == '0') break;

            string curStr = s.substr(pos, i - pos + 1);
            long long curNum = stoll(curStr);

            if (pos == 0) {
                // first number, no operator
                dfs(s, target, i + 1, curNum, curNum, curStr, result);
            } else {
                dfs(s, target, i + 1, eval + curNum, curNum, path + "+" + curStr, result);
                dfs(s, target, i + 1, eval - curNum, -curNum, path + "-" + curStr, result);
                dfs(s, target, i + 1, eval - multed + multed * curNum, multed * curNum, path + "*" + curStr, result);
            }
        }
    }
};
