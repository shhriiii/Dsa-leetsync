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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        int n = d.size();
        map<int , TreeNode*> mp;
        for(int i =0;i<n;i++){
            if(mp.find(d[i][0])!=mp.end()){
                TreeNode* node = mp[d[i][0]];
                if(mp.find(d[i][1])==mp.end()){
                    TreeNode* node2 = new TreeNode(d[i][1]);
                    mp[d[i][1]]=node2;
                    if(d[i][2]==1){
                        node->left = node2;
                    }
                    else node->right = node2;




                }
                else{
                    TreeNode* node2 = mp[d[i][1]];
                    if(d[i][2]==1){
                        node->left = node2;
                    }
                    else node->right = node2;
                }

            }
            else{
                TreeNode* node = new TreeNode(d[i][0]);
                mp[d[i][0]]=node;
                if(mp.find(d[i][1])==mp.end()){
                    TreeNode* node2 = new TreeNode(d[i][1]);
                    mp[d[i][1]]=node2;

                    if(d[i][2]==1){
                        node->left =node2;
                    }
                    else{
                        node->right = node2;
                    }

                }
                else{
                    TreeNode* node2 = mp[d[i][1]];
                    if(d[i][2]==1){
                        node->left=node2;
                    }
                    else{
                        node->right=node2;  
                    }
                }
            }
        }
        set<int> st;
        for(int i =0;i<n;i++){
            st.insert(d[i][1]);
        }
        TreeNode* ans;
        for(int i =0;i<n;i++){
            if(st.find(d[i][0])==st.end()) ans= mp[d[i][0]];
        }
        return ans;


        
    }
};