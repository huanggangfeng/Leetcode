// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/submissions/

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
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        maxPath = INT_MIN;
        getMaxPath(root);
        return maxPath;
    }
    
    int getMaxPath(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = max(0, getMaxPath(root->left));
        int right = max(0, getMaxPath(root->right));
        int ret = root->val + left + right;
        if (ret > maxPath)
            maxPath = ret;
        // 这里只能返回值只能包含root 和一个子树的贡献值
        return root->val + max(left, right);
    }

private:
    int maxPath;
};