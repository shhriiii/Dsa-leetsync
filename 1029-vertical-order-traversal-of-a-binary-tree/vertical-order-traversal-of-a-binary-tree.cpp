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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int , int>>> q;
        q.push({root , {0,0}});
        while(q.size()>0){
            TreeNode* cnode = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            nodes[x][y].insert(cnode->val);
            if(cnode->left){
                q.push({cnode->left , {x-1,y+1}});

            }
            if(cnode->right){
                q.push({cnode->right,{x+1,y+1}});
            }

        }
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};