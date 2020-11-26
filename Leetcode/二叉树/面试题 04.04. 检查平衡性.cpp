// 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。


// 示例 1:
// 给定二叉树 [3,9,20,null,null,15,7]
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回 true 。
// 示例 2:
// 给定二叉树 [1,2,2,3,3,null,null,4,4]
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
// 返回 false 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/check-balance-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
private:
    bool isBalance = true;
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        if (!isBalance)
            return false;
        int left = helper(root->left);
        int right = helper(root->right);
        if (abs(left, right) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int helper(TreeNode *node) {
        if (node == NULL)
            return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        return max(left, right) + 1;
    }

    inline int abs(const int &a, const int &b) {
        return a > b ? a - b : b - a;
    }
};