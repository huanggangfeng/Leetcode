// https://leetcode-cn.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* p = head;
        while (p != NULL) {
            count++;
            p = p->next;
        }

        if (count <= 1 || k == 0)
            return head;
        if (k >= count) {
            k = k % count;
        }

        if (k == 0)
            return head;

        ListNode *p_fast = head;
        ListNode *p_slow = head;
        while (k > 0) {
            p_fast = p_fast->next;
            k--;
        }
    
        while (p_fast->next != NULL) {
            p_fast = p_fast->next;
            p_slow = p_slow->next;
        }
        ListNode* dummphead = p_slow->next;
        p_slow->next = NULL;
        p_fast->next = head;
        return dummphead;
    }
};