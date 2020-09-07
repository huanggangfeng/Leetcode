// https://leetcode-cn.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL)
                return false;
            if (fast != NULL && fast->next != NULL)
                fast = fast->next->next;
            if (slow)
                slow = slow->next;
        }
        return true;
    }
};