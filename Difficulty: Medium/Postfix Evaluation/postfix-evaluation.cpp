class Solution {
public:
int floordiv(int b, int a) {
    return floor((double)b / a);
}

    int solve(char ch, int a, int b) {
        switch (ch) {
            case '+': return b + a;
            case '-': return b - a;
            case '*': return b * a;
            case '/': return floordiv(b, a);
            case '^': return (int)pow(b, a); 
        }
        return 0;
    }

    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i].size() == 1 && !isdigit(arr[i][0]) && !(arr[i][0] == '-' && arr[i].size() > 1)) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                char opr = arr[i][0];
                st.push(solve(opr, a, b));
            } else {
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
    }
};