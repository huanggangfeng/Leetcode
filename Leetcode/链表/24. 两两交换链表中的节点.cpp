// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *fakeHead = new ListNode;
        ListNode *tail = fakeHead;

        while (head != NULL && head->next != NULL) {
            ListNode *p1 = head;
            ListNode *p2 = head->next;
            head = head->next->next;
            tail->next = p2;
            p2->next = p1;
            p1->next = head;
            tail = p1;
        }
        tail = fakeHead->next;
        fakeHead->next = NULL;
        delete fakeHead;
        return tail;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummyHead = new ListNode;
        ListNode *tail = dummyHead;
        while (head != NULL && head->next != NULL) {
            ListNode *tmp = head->next->next;
            tail->next = head->next;
            tail->next->next = head;
            tail = head;
            head = tmp;
        }

        if (head != NULL) {
            tail->next = head;
            tail = tail->next;
        }

        tail->next = NULL;
        return dummyHead->next;
    }
};