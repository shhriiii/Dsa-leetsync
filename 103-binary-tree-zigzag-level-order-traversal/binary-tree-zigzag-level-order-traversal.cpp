
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> curr;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();  // IMPORTANT: remove processed node

                curr.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            if (level % 2 == 0) {
                ans.push_back(curr);
            } else {
                reverse(curr.begin(), curr.end());
                ans.push_back(curr);
            }

            level++;
        }

        return ans;
    }
};
