// https://leetcode-cn.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        ListNode* dummyHead = new ListNode;
        ListNode* tail = dummyHead;
        bool all_empty = false;
        do {
            int value = INT_MAX;
            all_empty = true;
            int index = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    all_empty = false;
                    if (index == -1 || lists[i]->val < value) {
                        value = lists[i]->val;
                        all_empty = false;
                        index = i;
                    }
                }
            }
            if (index != -1) {
                tail->next = lists[index];
                lists[index] = lists[index]->next;
                tail = tail->next;
            }
        } while (!all_empty);

        tail->next = NULL;
        return dummyHead->next;
    }
};