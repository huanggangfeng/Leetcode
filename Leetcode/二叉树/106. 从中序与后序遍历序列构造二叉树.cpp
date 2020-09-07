// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = inorder.size()-1;
        return buildTree(postorder, pos, inorder, 0, inorder.size() - 1);
    }

    // pos 是后序的最后位置，
    TreeNode* buildTree(vector<int>& postorder, int& pos, vector<int>& inorder, int left, int right) {
        if (pos < 0 || left > right)
            return NULL;
        int p = left;
        // 找到分割点
        while (p <= right && postorder[pos] != inorder[p])
            p++;
        TreeNode* node = new TreeNode(postorder[pos]);
        if (p+1 <= right)
            node->right = buildTree(postorder, --pos, inorder, p+1, right);
        if (left <= p-1)
            node->left = buildTree(postorder, --pos, inorder, left, p-1);
        return node;
    }
};
