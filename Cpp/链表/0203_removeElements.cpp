/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode-cn.com/problems/remove-linked-list-elements/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode *dummyHead(new ListNode);
        ListNode *cur = dummyHead;
        while (head != NULL) {
            if (head->val != val) {
                cur->next = head;
                cur = cur->next;
            }
            head= head->next;
        }
        cur->next = NULL;
        return dummyHead->next;
    }
};