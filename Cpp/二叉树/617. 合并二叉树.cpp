// https://leetcode-cn.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        TreeNode *node = NULL;
        if (t1 != NULL && t2 != NULL) {
            node = t1;
            node->val += t2->val;
            node->left = mergeTrees(t1->left, t2->left);
            node->right = mergeTrees(t1->right, t2->right);
        } else if (t2 != NULL) {
            node = t2;
        }
        
        return node;
    }
};