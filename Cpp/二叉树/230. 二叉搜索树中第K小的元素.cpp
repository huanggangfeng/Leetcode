// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

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
    int n = 0;
    int res;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }

    // 二叉搜索树的中序遍历其实就是按顺序输出所有元素，所以利用这个特效，中序遍历即可，遇到第k个元素停止遍历，返回值
    void  dfs(TreeNode* root,int k){
          if(!root)
            return;
          dfs(root->left, k);
          n++;
          if(n==k)
            res=root->val;
          dfs(root->right,k);
    }
};