// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/

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
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;
        deque<TreeNode *> q;
        q.push_back(root);
        bool reverse = false;
        while (!q.empty()) {
            int count = q.size();
            vector<int> tmp;
            if (!reverse) {
                while (count--) {
                    TreeNode *node = q.front();
                    tmp.push_back(node->val);
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);
                    if (node->right)
                        q.push_back(node->right);
                }
                reverse = true;
            } else {
                while (count--) {
                    TreeNode *node = q.back();
                    tmp.push_back(node->val);
                    q.pop_back();
                    //  这里先右后左
                    if (node->right)
                        q.push_front(node->right);
                    if (node->left)
                        q.push_front(node->left);
                }
                reverse = false;
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};