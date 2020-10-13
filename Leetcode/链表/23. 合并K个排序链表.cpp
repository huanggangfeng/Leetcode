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

        do {
            int value = INT_MAX;
            int index = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    if (lists[i]->val < value) {
                        index = i;
                        value = lists[i]->val;
                    }
                }
            }

            if (index == -1)
                break;
            else {
                tail->next = lists[index];
                lists[index] = lists[index]->next;
                tail = tail->next;
            }
            
        } while (true);

        tail->next = NULL;
        return dummyHead->next;
    }
};