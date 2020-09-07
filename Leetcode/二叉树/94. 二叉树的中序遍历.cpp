// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
    void dfs(TreeNode* root, vector<int> &result) {
        if (root == NULL)
            return;
        dfs(root->left, result);
        result.emplace_back(root->val);
        dfs(root->right, result);
    }
};

// 非递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                ret.emplace_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return ret;
    }
};