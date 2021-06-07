
// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

// 假设一个二叉搜索树具有如下特征：

// 节点的左子树只包含小于当前节点的数。
// 节点的右子树只包含大于当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
// 示例 1:

// 输入:
//     2
//    / \
//   1   3
// 输出: true
// 示例 2:

// 输入:
//     5
//    / \
//   1   4
//      / \
//     3   6
// 输出: false
// 解释: 输入为: [5,1,4,null,null,3,6]。
//      根节点的值为 5 ，但是其右子节点值为 4 。


// https://leetcode-cn.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 二叉搜索树中序遍历一直有序，所以中序遍历，然后只要出现逆序对，则直接返回false
class Solution {
    TreeNode *previous = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        return inOrderReverse(root);
    }

    bool inOrderReverse(TreeNode *root) {
        if (root == NULL)
            return true;
        if (!inOrderReverse(root->left))
            return false;

        if (previous != nullptr) {
            if (previous->val >= root->val)
                return false;
        }
        previous = root;
        if (!inOrderReverse(root->right))
            return false;
        return true;
    }
};


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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;

        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long min, long max) {
        if (root == nullptr)
            return true;
        // cout << "Root:" << root->val << "\tMin:" << min << "\tMax:" << max << "\n";
        bool left = helper(root->left, min, root->val);
        if (!left)
            return false;
        bool right = helper(root->right, root->val, max);
        if (!right)
            return false;
        return (root->val > min && root->val < max);
    }
};