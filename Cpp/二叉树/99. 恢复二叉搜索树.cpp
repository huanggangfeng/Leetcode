// https://leetcode-cn.com/problems/recover-binary-search-tree/

// 二叉搜索树中的两个节点被错误地交换。

// 请在不改变其结构的情况下，恢复这棵树。

// 示例 1:

// 输入: [1,3,null,null,2]

//    1
//   /
//  3
//   \
//    2

// 输出: [3,1,null,null,2]

//    3
//   /
//  1
//   \
//    2
// 示例 2:

// 输入: [3,1,4,null,null,2]

//   3
//  / \
// 1   4
//    /
//   2

// 输出: [2,1,4,null,null,3]

//   2
//  / \
// 1   4
//    /
//   3

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/recover-binary-search-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  Solution: 对于二叉搜索树，中序遍历应该是有序的，所以中序遍历，然后找出它的逆序对，
//  两个交互的结点： first 和second，first是第一个逆序对中的较大值，second应该是最后一个逆序对中的最小值，
//  所以找到它们，纪录下来，最后交互回去即可
class Solution {
private:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *previous = nullptr;
public:
    void recoverTree(TreeNode* root) {
        inOrderReverse(root);
        if (first != nullptr && second != nullptr) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }

    void inOrderReverse(TreeNode *root) {
        if (root == nullptr)
            return;
        inOrderReverse(root->left);
        if (previous != nullptr) {
            if (root->val < previous->val) {
                second = root;
                if (first == nullptr)
                    first = previous;
            }
        }
        previous = root;
        inOrderReverse(root->right);
    }
};