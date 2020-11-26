// 实现一个函数，检查一棵二叉树是否为二叉搜索树。

// 示例 1:
// 输入:
//     2
//    / \
//   1   3
// 输出: true
// 示例 2:
// 输入:
//     5
//    / \
//   1   4
//      / \
//     3   6
// 输出: false
// 解释: 输入为: [5,1,4,null,null,3,6]。
//      根节点的值为 5 ，但是其右子节点值为 4 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/legal-binary-search-tree-lcci
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
private:
TreeNode* prev = nullptr;
bool result = true;
public:
    bool isValidBST(TreeNode* root) {
        InOrderTraverse(root);
        return result;
    }

    void InOrderTraverse(TreeNode* root) {
        if (root == NULL)
            return;
        InOrderTraverse(root->left);
        if (prev != nullptr && prev->val >= root->val) {
            result = false;
            return;
        }
        prev = root;
        InOrderTraverse(root->right);
    }
};