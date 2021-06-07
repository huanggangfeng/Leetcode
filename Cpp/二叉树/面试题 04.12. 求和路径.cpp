// 给定一棵二叉树，其中每个节点都含有一个整数数值(该值或正或负)。设计一个算法，打印节点数值总和等于某个给定值的所有路径的数量。注意，路径不一定非得从二叉树的根节点或叶节点开始或结束，但是其方向必须向下(只能从父节点指向子节点方向)。

// 示例:
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:

// 3
// 解释：和为 22 的路径有：[5,4,11,2], [5,8,4,5], [4,11,7]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/paths-with-sum-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        int ret = 0;
        int path = 0;
        dfs(root, sum, path, ret);
        ret += pathSum(root->left, sum);
        ret += pathSum(root->right, sum);
        return ret;
    }

    void dfs(TreeNode *root, const int &sum, int path, int &result) {
        if (root == NULL)
            return;
        path += root->val;
        if (path == sum)
            ++result;
        if (root->left == NULL && root->right == NULL) {
            return;
        }
        dfs(root->left, sum, path, result);
        dfs(root->right, sum, path, result);
    }
};