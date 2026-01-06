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
    int maxLevelSum(TreeNode* root) {
        int maxSum = root->val;
        int maxLevel = 1;
        queue <TreeNode*> q;
        int currLevel = 1;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            int currSum =0;
            for(int node = 0 ;node <size ;node++){
                TreeNode* currNode = q.front();
                q.pop();
                currSum += currNode->val;

                if(currNode->left){
                    q.push(currNode->left);
                    
                }
                if(currNode->right){
                    q.push(currNode->right);
                }

            }
            if(currSum > maxSum){
                maxSum = currSum;
                maxLevel = currLevel;
            }
            currLevel++;
        }
        return maxLevel;
        
    }
};