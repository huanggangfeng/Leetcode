// https://leetcode-cn.com/problems/path-sum/
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return sum == root->val;
        bool left = false;;
        bool right = false;
        if (root->left)
            left = hasPathSum(root->left, sum - root->val);
        if (root->right)
            right = hasPathSum(root->right, sum - root->val);
        if (left || right)
            return true;
        return false;
    }
};