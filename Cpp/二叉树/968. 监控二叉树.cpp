// https://leetcode-cn.com/problems/binary-tree-cameras/
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
    int res = 0;
    int minCameraCover(TreeNode* root) 
    {
        if(dfs(root) == 0)
        {
            res++;  
        }
        return res;
    }
    int dfs(TreeNode* root)
    {

        //0：未被覆盖(当前节点未被照到)
        //1：已被覆盖(摄像头已经照到这个节点)
        //2：需放置摄像头

        if(root == NULL)
            return 1;

        int left = dfs(root->left);
        int right = dfs(root->right);

        //一个节点左右确定后，判断左右节点情况
        //所有情况00,01,02,11,12,22
        //左右孩子中有一个未被覆盖，则当前节点需要放置摄像头，当前节点标志为2
        if(left == 0 || right== 0)
        {
            res++;
            return 2;
        }
        //左右孩子均为已覆盖状态,则当前节点未被覆盖，标志为0
        if(left == 1 && right == 1)
        {
            return 0;
        }
        //若左右孩子为一个覆盖一个放置了摄像头，则当前节点为已被覆盖，标志为1
        if(left + right >= 3)
        {
            return 1;
        }
        //此时已经组合完了根节点所有情况，随便返回一个整数即可
        return 0;
    }
};