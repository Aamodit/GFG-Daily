class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaves;
        int n = preorder.size();

        function<void(int, int, int&)> findLeaves = [&](int minVal, int maxVal, int &index) {
            if (index >= n || preorder[index] < minVal || preorder[index] > maxVal)
                return;

            int rootVal = preorder[index++];
            int i = index;

            // Recurse for left subtree
            findLeaves(minVal, rootVal - 1, index);

            // Recurse for right subtree
            findLeaves(rootVal + 1, maxVal, index);

            // If index didn't move after left and right calls, it's a leaf
            if (i == index)
                leaves.push_back(rootVal);
        };

        int idx = 0;
        findLeaves(INT_MIN, INT_MAX, idx);
        return leaves;
    }
};
