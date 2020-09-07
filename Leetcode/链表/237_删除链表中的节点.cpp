// https://leetcode-cn.com/problems/delete-node-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr)
            return;
        ListNode *del = node->next;
        // 因为不知道head，所以也没法知道node 的前一个
        // 这里把node->next的值赋值给了node, 然后删除了node->next, 效果就像是删除了node结点
        node->val = node->next->val;
        node->next = node->next->next;
        delete del;
    }
};