// https://leetcode-cn.com/problems/binary-tree-paths/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL)
            return ret;
        string path = to_string(root->val);
        dfs(ret, root, path);
        return ret;
    }

    void dfs(vector<string> &ret, TreeNode *root, string path) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {          
            ret.emplace_back(path);
            return;
        }

        path += "->";
        if (root->left) 
            dfs(ret, root->left, path + to_string(root->left->val));
        if (root->right)
            dfs(ret, root->right, path + to_string(root->right->val));
    }
};