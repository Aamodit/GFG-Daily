class Solution {
public:

    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    bool palindromePair(vector<string>& arr) {

        unordered_map<string, int> mp;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {

            string word = arr[i];

            for (int j = 0; j <= word.size(); j++) {

                string left = word.substr(0, j);
                string right = word.substr(j);

                // left palindrome
                if (isPal(left, 0, left.size() - 1)) {

                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());

                    if (mp.count(revRight) && mp[revRight] != i)
                        return true;
                }

                // right palindrome
                if (isPal(right, 0, right.size() - 1)) {

                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());

                    if (mp.count(revLeft) && mp[revLeft] != i)
                        return true;
                }
            }
        }

        return false;
    }
};