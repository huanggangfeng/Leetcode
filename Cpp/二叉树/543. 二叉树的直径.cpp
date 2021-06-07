/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 直径 = max(left, right) + 1

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ret = 0;
        depth(root, ret);
        return ret - 1;
    }

    int depth(TreeNode *root, int &result) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left, result);
        int right = depth(root->right, result);
        result = max(result, left + right + 1);
        return max(left, right) + 1;
    }
};
