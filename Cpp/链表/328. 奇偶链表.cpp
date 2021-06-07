// https://leetcode-cn.com/problems/odd-even-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *dummyHead1 = new ListNode;
        ListNode *dummyHead2 = new ListNode;
        ListNode *tail1 = dummyHead1;
        ListNode *tail2 = dummyHead2;
        int length = 0;
        while (head != nullptr) {
            if (length % 2 == 0) {
                tail1->next = head;
                tail1 = tail1->next;
            } else {
                tail2->next = head;
                tail2 = tail1->next;
            }
            length++;
            head = head->next;
        }
        tail1->next = dummyHead2->next;
        tail2->next = nullptr;
        return dummyHead1->next;
    }
};