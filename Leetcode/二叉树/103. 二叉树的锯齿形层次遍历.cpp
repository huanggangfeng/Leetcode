// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int len = q.size();
            vector<int> tmp;
            for (int i = 0; i < len; i++) {
                root = q.front();
                tmp.emplace_back(root->val);
                q.pop();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            if (level % 2 == 1)
                 reverse(tmp.begin(), tmp.end());
        level++;
            ret.emplace_back(tmp);
        }
        return ret;
    }
};