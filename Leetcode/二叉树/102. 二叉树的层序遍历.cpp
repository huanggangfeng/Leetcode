// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return vector<vector<int>> {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            vector<int> tmp;
            int count = q.size();
            while(count) {
                TreeNode*p = q.front();
                tmp.emplace_back(p->val);
                if (p->left)
                    q.emplace(p->left);
                if (p->right)
                    q.emplace(p->right);
                q.pop();
                count--;
            }
            ret.emplace_back(tmp);
        }
        return ret;
    };
};