// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B)
            return false;
        bool res = false;
        // 如果在 A 中匹配到了与 B 的根节点的值一样的节点
        if(A -> val == B -> val)
            res = doesAHaveB(A, B);
        // 如果匹配不到，A 往左
        if(!res)
            res = isSubStructure(A -> left, B);
        // 还匹配不到，A 往右
        if(!res)
            res = isSubStructure(A -> right, B);
        return res;
    }

    bool doesAHaveB(TreeNode *r1, TreeNode *r2)
    {
        // 如果 B 已经遍历完了，true
        if(!r2)
            return true;
        // 如果 B 还有，但 A 遍历完了，那 B 剩下的就没法匹配了，false
        if(!r1)
            return false;
        // 不想等，false
        if(r1 -> val != r2 -> val)
            return false;
        return doesAHaveB(r1 -> left, r2 -> left) && doesAHaveB(r1 -> right, r2 -> right);
    }
};
