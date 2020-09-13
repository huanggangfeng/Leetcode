// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

// 要求
// 在二叉树的后序遍历中，常常依靠队列，要么在队列中前向插入，要么利用队列去判断该节点是否遍历过，现在要求只能利用栈去做，不能用队列去辅助判断（即，只允许在队列尾部添加答案）

// 思路
// 这道题的难点在于仅利用栈去判断该节点是否为父结点，创新性思路是每次在栈中压入父节点后压入nullptr，之后再依次压入右子节点和左子节点。

// 作者：dcoliversun
// 链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/a-li-mian-shi-ti-zhi-yong-zhan-qu-zuo-er-cha-shu-d/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;

        while (!s.empty()) {
            TreeNode *node = s.top();
            if (node == nullptr) {
                s.pop();
                res.push_back(s.top()->val);
                s.pop();
            } else {
                s.push(nullptr);
                if (node->right)
                    s.push(node->right);
                if (node->left)
                    s.push(node->left);
            }
        }
        return res;
    }
};