// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int pos = 0;
        return buildBinaryTree(preorder, pos, inorder, 0, n-1);
    }

    TreeNode* buildBinaryTree(vector<int>& preorder, int &pos, vector<int>& inorder, int left, int right) {
        if (pos >= preorder.size())
            return NULL;
        int i = left;
        // 找到根节点在中序中的位置，
        for (; i <= right; i++) {
            if (inorder[i] == preorder[pos])
                break;
        }

        TreeNode *node = new TreeNode(preorder[pos]);        

        // 递归构造整个左子树
        if (i-1 >= left)
            node->left = buildBinaryTree(preorder, ++pos, inorder, left, i-1);
        // 递归构造整个右子树
        if (i+1 <= right)
            node->right = buildBinaryTree(preorder, ++pos, inorder, i+1, right);
        return node;
    }
};