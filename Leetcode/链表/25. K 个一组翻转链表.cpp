// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1)   
            return head;
        ListNode *dummyHead = new ListNode(-1);
        ListNode *tail = dummyHead;
        ListNode *index = head;
        while (index != NULL) {
            ListNode *tmpHead = index;
            int count = k;
            while (count > 0 && index != NULL) {
                index = index->next;
            }

            if (count == 0) {
                tail->next = reverse(tmpHead, k);
                tail = tmpHead;
            } else
                tail->next = tmpHead;
        }

        return dummyHead->next;
    }
};