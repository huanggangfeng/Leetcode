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
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode* pre = nullptr;
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node->right != nullptr)
                s.push(node->right);
            if (node->left != nullptr)
                s.push(node->left);  
            if (pre != nullptr) {
                pre->left = nullptr;
                pre->right = node;
            }
            pre = node;
        }
    }
};