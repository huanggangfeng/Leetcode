// 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

// 示例 1:

// 输入: 1->2->3->3->4->4->5
// 输出: 1->2->5
// 示例 2:

// 输入: 1->1->1->2->3
// 输出: 2->3

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummyHead = new ListNode;
        ListNode *tail = dummyHead;
        while (head != NULL) {
            int val = head->val;
            int count = 1;
            while (head->next != nullptr && head->next->val == val) {
                head = head->next;
                ++count;
            }
            if (count == 1) {
                tail->next = head;
                head = head->next;
                tail = tail->next;
            } else {
                head = head->next;
            }
        }
        tail->next = nullptr;
        return dummyHead->next;
    }
};