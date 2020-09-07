// https://leetcode-cn.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode;
        ListNode *tail = head;
        while (l1 != NULL || l2 != NULL || carry) {
            int value = carry;
            if (l1) {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                value += l2->val;
                l2 = l2->next;
            }
            carry = value/10;
            ListNode *p = new ListNode(value%10);
            tail->next = p;
            tail = tail->next;
        }
        ListNode *ret = head->next;
        head->next = NULL;
        delete head;
        return ret;
    }
};