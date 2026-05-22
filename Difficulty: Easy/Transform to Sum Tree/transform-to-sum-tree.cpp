class Solution {
  public:
  
    int solve(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        // Get left and right subtree sums
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        
        // Store original node value
        int oldValue = root->data;
        
        // Update node with sum of left and right subtree
        root->data = leftSum + rightSum;
        
        // Return original subtree sum
        return oldValue + root->data;
    }
  
    void toSumTree(Node *root) {
        solve(root);
    }
};