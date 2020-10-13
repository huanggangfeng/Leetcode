/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 在二叉搜索树中，中序遍历会将树中节点按数值大小顺序输出。只需要遍历计算相邻数的差值，取其中最小的就可以了。


class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return result;
    }

    void dfs(TreeNode *root) {
        if (root == NULL)
            return;
        dfs(root->left);
        if (previous == -1) {
            previous = root->val;
        } else {
            result = min(result, root->val - previous);
            previous = root->val;
        }
        dfs(root->right);
    }
private:
    int previous = -1;
    int result = INT_MAX;
};