// https://leetcode-cn.com/problems/reorder-list/


// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例 1:

// 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
// 示例 2:

// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = reverse(slow->next);
        slow->next = nullptr;
        head = merge(head, second);
    }

    ListNode* reverse(ListNode* head) {
        ListNode *dummyHead = new ListNode(-1);
        while (head) {
            ListNode *tmp = head->next;
            head->next = dummyHead->next;
            dummyHead->next = head;
            head = tmp;
        }  

        return dummyHead->next;     
    }

    ListNode* merge(ListNode* list1, ListNode *list2) {
        ListNode *dummyHead  = new ListNode;
        ListNode *tail = dummyHead;
        while (list1 != nullptr && list2 != nullptr) {
            tail->next = list1;
            list1 = list1->next;
            tail->next->next = list2;
            list2 = list2->next;
            tail = tail->next->next;
        }

        if (list1) {
            tail->next = list1;
        }

        if (list2) {
            tail->next = list2;
        }

        return dummyHead->next;
    }
};