// https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 简单的层次遍历
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if (root == NULL)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            double total = 0.0;
            int i = 0;
            while (i < count) {
                TreeNode* node = q.front();
                total += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
                i++;
            }
            ret.emplace_back(total/count);
        }
        return ret;
    }
};