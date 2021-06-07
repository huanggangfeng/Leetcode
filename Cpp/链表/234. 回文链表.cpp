// https://leetcode-cn.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode *p = head;
        int length = 0;
        while (p != NULL) {
            p = p->next;
            length++;
        }
        if (length == 1)
            return true;
        // cout << length << "\n";
        int middle = (length + 1) /2;
        p = head;
        while (middle != 0) {
            p = p->next;
            middle--;
        }
        // cout << "2nd linklist start from: " << p->val << "\n";
        p = reverse(p);
        int ret = true;
        while (p != NULL) {
            // cout << "p:head" << p->val << ":" << head->val << "\n";
            if (p->val != head->val) {
                ret = false;
                break;
            }
            head = head->next;
            p = p->next;
        }
        return ret;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *dummyHead = new ListNode;
        ListNode *index;
        while (head != NULL) {
            index = head->next;
            head->next = dummyHead->next;
            dummyHead->next = head;
            head = index;
        }
        index = dummyHead->next;
        delete dummyHead;
        return index;
    }
};


