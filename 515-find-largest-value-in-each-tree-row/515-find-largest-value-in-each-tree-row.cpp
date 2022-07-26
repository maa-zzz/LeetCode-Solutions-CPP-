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
    vector<int> ans;
    void solve(TreeNode* root, int level){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->val);
        }
        else{
            ans[level] = max(ans[level], root->val);
        }
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return ans;
        solve(root,0);
        return ans;
    }
};