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
    
    TreeNode* solve(vector<int>& nums, int low, int high){
        TreeNode* root;
        if(low<=high){
            int mid = (low+high)/2;
            root = new TreeNode(nums[mid]);
            root->left = solve(nums,low, mid-1);
            root->right = solve(nums, mid+1, high);
            return root;
        }
        return NULL;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return solve(nums,low,high);
    }
};