class Solution {
  public:
  
    int l,r;
    int ans = 0;
    
    void solve(Node* root){
        if(!root){
            return;
        }
        
        int k = root->data;
        
        if(k >= l && k <= r){
            ans += k;
            solve(root->left);
            solve(root->right);
        }else if(k < l){
            solve(root->right);
        }else{
            solve(root->left);
        }
    }
    
    int nodeSum(Node* root, int l_, int r_) {
        l = l_ , r = r_;
        solve(root);
        return ans;
    }
};