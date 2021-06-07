// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/ 

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0)
            return head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        // 快指针先走n步
        while (n > 0 && p1 != nullptr) {
            p1 = p1->next;
            n--;
        }
        
        ListNode *del = nullptr；
        //  如果快指针已经走到尾了，那直接删除头元素
        if (p1 == nullptr)
            return head->next;

        while (p1->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *del = p2->next;
        p2->next = p2->next->next;
        delete del;
        return head;
    }
};