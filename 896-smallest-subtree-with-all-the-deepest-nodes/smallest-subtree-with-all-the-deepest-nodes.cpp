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
    int findLevel(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxLevel = INT_MIN;
        while (!q.empty()) {
            auto [currNode, level] = q.front();
            q.pop();
            maxLevel = max(maxLevel, level);
            if (currNode->left) q.push({currNode->left, level + 1});
            if (currNode->right) q.push({currNode->right, level + 1});
        }
        return maxLevel;
    }

    pair<TreeNode*, TreeNode*> findLeftmostAndRightmost(TreeNode* root, int l) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<TreeNode*> deepestLevel;

        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> currentLevel;
            for (int i = 0; i < n; ++i) {
                auto [node, level] = q.front();
                q.pop();
                if (level == l) {
                    currentLevel.push_back(node);
                }
                if (node->left) q.push({node->left, level + 1});
                if (node->right) q.push({node->right, level + 1});
            }
            if (!currentLevel.empty()) {
                deepestLevel = currentLevel;
            }
        }

        return {deepestLevel.front(), deepestLevel.back()};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        return root;
    }

    TreeNode*  subtreeWithAllDeepest(TreeNode* root) {
        int level = findLevel(root);
        auto [leftmost, rightmost] = findLeftmostAndRightmost(root, level);
        return lowestCommonAncestor(root, leftmost, rightmost);
    }
};
