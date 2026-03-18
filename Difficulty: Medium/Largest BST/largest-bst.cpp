class Solution {
  public:

    class Info {
      public:
        int size;
        int minVal;
        int maxVal;
        bool isBST;

        Info(int s, int mn, int mx, bool b){
            size = s;
            minVal = mn;
            maxVal = mx;
            isBST = b;
        }
    };

    int maxSize = 0;

    Info solve(Node* root){

        if(root == NULL){
            return Info(0, INT_MAX, INT_MIN, true);
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        // check BST condition
        if(left.isBST && right.isBST && 
           root->data > left.maxVal && root->data < right.minVal){

            int currSize = left.size + right.size + 1;

            maxSize = max(maxSize, currSize);

            return Info(
                currSize,
                min(root->data, left.minVal),
                max(root->data, right.maxVal),
                true
            );
        }

        return Info(0, 0, 0, false);
    }

    int largestBst(Node *root) {
        solve(root);
        return maxSize;
    }
};