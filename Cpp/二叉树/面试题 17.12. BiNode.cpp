// https://leetcode-cn.com/problems/binode-lcci/

// 二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

// 返回转换后的单向链表的头节点。

// 注意：本题相对原题稍作改动

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binode-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        // 虚拟头指针，这样在中序遍历中把遍历到的结点root保存在链表中，就可以直接更新遍历到的结点root，然后cur向前走一步，遍历也走向下一个
        TreeNode *head = new TreeNode(-1);
        TreeNode *cur = head;
        inorderTraversal(root, cur);
        return head->right;
    }

    void inorderTraversal(TreeNode *root, TreeNode *&cur) {
        if (root) {
            inorderTraversal(root->left, cur);
            cur->right = root; //将此节点赋给cur的右子树
            root->left = NULL;//将此节点的左子树赋值NULL
            cur = root; //更新
            inorderTraversal(root->right, cur);
        }
    }
};