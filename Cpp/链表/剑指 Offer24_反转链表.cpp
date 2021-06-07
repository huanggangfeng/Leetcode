// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/

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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *dummy_head = new ListNode;
        while (head != nullptr) {
            ListNode *tmp = dummy_head->next;
            dummy_head->next = head;
            // 先把head更新, 不然 dummy_head->next->next 更新会把后面结点也就是head->next弄丢
            head = head->next;
            dummy_head->next->next = tmp;
        }

        return dummy_head->next;
    }

    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr)
            return head;

        ListNode *ret = reverseList(head->next);
        // 把head和head->next反转
        head->next->next = head;
        // head应该变成最后一个元素，所以head->next = nullptr;
        head->next = nullptr;
        return ret;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr ||head->next == nullptr)
            return head;
        ListNode *followNode = head->next;
        ListNode *ret = reverseList(followNode);
        // 把head和head->next反转
        followNode->next = head;
        // head应该变成最后一个元素，所以head->next = nullptr;
        head->next = nullptr;
        return ret;
    }
};