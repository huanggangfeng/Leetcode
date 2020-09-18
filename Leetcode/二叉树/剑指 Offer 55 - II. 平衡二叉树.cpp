// 后序遍历求高度

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
	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
            return true;
		int depth = 0;
		return isBalanced(root, depth);
	}

	bool isBalanced(TreeNode* root, int &pDepth) {
		if (root == nullptr) {
            pDepth = 0;
            return true;
        }
		int left = 0, right = 0;
		if (isBalanced(root->left, left) && isBalanced(root->right, right))
		{
			int diff = left - right;
			if (abs(diff) <= 1)
			{
				pDepth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
};