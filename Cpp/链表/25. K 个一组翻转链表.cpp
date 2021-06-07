// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/class Solution {
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1)   
            return head;
        ListNode *prevHead = head;
        ListNode *nextHead = head;
        
        for (int i = 0; i < k; i++) {
            if (nextHead != NULL)
                nextHead = nextHead->next;
            else
                return head;
        }

        head = regverse(head, nextHead);
        prevHead->next = reverseKGroup(nextHead, k);
        return head;
    }

    // 反转从[head, end)这单链表
    ListNode* regverse(ListNode* head, ListNode* end) {
        ListNode *dummyHead = new ListNode;
        ListNode *tmp = dummyHead;
        while (head != end) {
            tmp = dummyHead->next;
            dummyHead->next = head;
            head = head->next;
            dummyHead->next->next = tmp;
        }

        return dummyHead->next;
    }
};