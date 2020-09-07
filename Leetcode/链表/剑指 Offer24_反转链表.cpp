// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/

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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *dummy_head(new ListNode);
        ListNode *p = head;
        while (p) {
            ListNode *tmp1 = dummy_head->next;
            ListNode *tmp2 = p->next;
            dummy_head->next = p;
            p->next = tmp1;
            p = tmp2;
        }

        return dummy_head->next;
    }
};