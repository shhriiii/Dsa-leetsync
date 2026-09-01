/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void helper(TreeNode* root) {
        if(root==NULL) return ;
        if(root->left!=NULL) helper(root->left);
        ans.push_back(root->val);
        if(root->right!=NULL) helper(root->right);
        return;

    }
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        helper(root);
        return ans;
    }
};