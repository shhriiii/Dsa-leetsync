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
vector<pair<int , TreeNode*>> inorder;
    void dfs(TreeNode* root){
        if(root->left!=NULL) dfs(root->left);
        inorder.push_back({root->val,root});
        if(root->right!=NULL) dfs(root->right);
        if(!root->left && !root->right){
            return;
        }

    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        vector<int> vals;
        for(int i =0;i<inorder.size();i++){
            vals.push_back(inorder[i].first);
        }
        sort(vals.begin(),vals.end());
        int pos1=-1;
        int pos2=-1;
        for(int i =0;i<inorder.size();i++){
            if(inorder[i].first!=vals[i] && pos1==-1){
                pos1=i;
            }
            if(inorder[i].first!=vals[i] && pos1!=-1){
                pos2=i;
            }

           

        }
        swap(inorder[pos1].second->val , inorder[pos2].second->val);
        
        
        
    }
};