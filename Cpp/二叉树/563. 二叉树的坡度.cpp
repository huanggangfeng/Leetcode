// https://leetcode-cn.com/problems/binary-tree-tilt/

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
    int findTilt(TreeNode* root) {
        int ret = 0;
        Tilt(root, ret);
        return ret;        
    }

    int Tilt(TreeNode* root, int &result) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;

        int left = Tilt(root->left, result);
        int right = Tilt(root->right, result);
        if (left > right)
            result += (left - right);
        else
            result += (right - left);
        return left + right + root->val;
    }
};