// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (k != 0 && fast != NULL) {
            fast =fast->next;
            k--;
        }

        if (k == 0) {
            while (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }
};