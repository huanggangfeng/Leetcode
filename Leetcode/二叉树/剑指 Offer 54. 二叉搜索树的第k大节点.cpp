// https://leetcode-cn.com/submissions/detail/91751472/
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
    int value;
    int count;
    int kthLargest(TreeNode* root, int k) {
        value = -1;
        inorder(root, k);
        return value;
    }
    
    void inorder(TreeNode* root, int k) {
        if (root == NULL)
            return;
        inorder(root->right, k);
        count++;
        if (count == k)
            value = root->val;
        inorder(root->left, k);
    }

};