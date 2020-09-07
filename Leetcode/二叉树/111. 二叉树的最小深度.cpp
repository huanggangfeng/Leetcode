// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if (root == 0)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        // 本题[1,2]这个树最小深度是2， 也就是针对一边为null的树， 告诉是不为null的另一边+1
        // 有一边为空，这个时候，返回不为0的那个 + 1
        if (left == 0 || right == 0)
            return left + right + 1;
        return left < right? left + 1 :right + 1;
    }
};


// 广度优先遍历
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == 0)
            return 0;
        queue<TreeNode*> s;
        int hight = 1;
        s.push(root);
        while (!s.empty()) {
            int size = s.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = s.front();
                s.pop();
                // cout << "node:" << node->val << "\n";
                if (node->left == NULL && node->right == NULL)
                    return hight;
                
                if (node->left)
                    s.push(node->left);
                if (node->right)
                    s.push(node->right);
            }
            hight++;
        }
        return hight;
    }
};