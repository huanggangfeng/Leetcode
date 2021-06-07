// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL)
            return ret;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            ret.push_back(node->val);
            s.pop();
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
        return ret;
    }
};