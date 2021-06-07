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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode *result = new TreeNode(root->val);
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* root, TreeNode* result) {
        if (root == NULL)
            return;
        if (root->left)
            result->right = new TreeNode(root->left->val);
        if (root->right)
            result->left = new TreeNode(root->right->val);

        dfs(root->left, result->right);
        dfs(root->right, result->left);
    }
};
