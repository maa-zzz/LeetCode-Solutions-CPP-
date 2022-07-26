/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int  sum = 0;
    
    void solve(TreeNode* root){
        if(root == NULL) return;
        if(root->right) solve(root->right);
        sum+=root->val;
        root->val = sum; //traverse to the greatest element first, them start adding to the sum
        if(root->left) solve(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        solve(root);
        return root;
    }
};