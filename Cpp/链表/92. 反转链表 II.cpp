// 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

// 说明:
// 1 ≤ m ≤ n ≤ 链表长度。

// 示例:

// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
// 输出: 1->4->3->2->5->NULL

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummyHead = new ListNode;
        dummyHead->next = head;
        ListNode *start = dummyHead;
        for (int i = 0; i < m -1; i++) {
            start = start ->next;
        }

        ListNode *end = start;
        int offset = n - m;
        for (int i = 0; i <= offset; i++) {
            end = end->next;
        }

        ListNode *tmp1 = end->next; 
        ListNode *tmp2 = start->next; 
        end->next = nullptr;
        start->next = reverse(tmp2);
        tmp2->next = tmp1;
        return dummyHead->next;
    }

    ListNode *reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummyHead = new ListNode;
        while (head != nullptr) {
            ListNode *tmp = dummyHead->next;
            dummyHead->next = head;
            head = head->next;
            dummyHead->next->next = tmp;
        }
        return dummyHead->next;
    }
};