class Solution {
public:
    static const int B = 15; // since max arr[i] <= 50000 < 2^16

    struct Node {
        int cnt = 0;
        Node* child[2] = {nullptr, nullptr};
    };

    Node* root = new Node();

    void insert(int x) {
        Node* cur = root;
        for (int i = B; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->child[b]) cur->child[b] = new Node();
            cur = cur->child[b];
            cur->cnt++;
        }
    }

    // count numbers y already in trie s.t. x^y < k
    int countLess(int x, int k) {
        Node* cur = root;
        int ans = 0;

        for (int i = B; i >= 0; --i) {
            if (!cur) break;

            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == 1) {
                // take subtree where XOR bit = 0 → ybit = xb
                Node* same = cur->child[xb];
                if (same) ans += same->cnt;

                // continue with branch that makes XOR bit = 1 → ybit = 1-xb
                cur = cur->child[1 - xb];
            } else {
                // must match exactly: ybit = xb
                cur = cur->child[xb];
            }
        }

        return ans;
    }

    int cntPairs(vector<int>& arr, int k) {
        int ans = 0;

        for (int x : arr) {
            ans += countLess(x, k);
            insert(x);
        }

        return ans;
    }
};
