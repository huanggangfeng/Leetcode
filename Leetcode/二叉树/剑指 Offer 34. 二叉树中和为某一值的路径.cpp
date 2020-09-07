// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;
        vector<int> path;

        helper(ret, root, path, sum);
        return ret;
    }

    void helper(vector<vector<int>> &result, TreeNode* root, vector<int> path, int sum) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            path.emplace_back(root->val);
            result.emplace_back(path);
            return;
        }

        path.emplace_back(root->val);
        if (root->left) {
            helper(result, root->left, path, sum - root->val);
        }

        if (root->right) {
            helper(result, root->right, path, sum - root->val);
        }
    }
};