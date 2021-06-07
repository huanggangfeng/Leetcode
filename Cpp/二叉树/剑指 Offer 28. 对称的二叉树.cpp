// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

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
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL || root1->val != root2->val)
            return false;
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return dfs(root->left, root->right);
    }
};
