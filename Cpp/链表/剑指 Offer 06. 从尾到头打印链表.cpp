// https://leetcode-cn.com/submissions/detail/91748658/
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        while (head != NULL) {
            ret.emplace_back(head->val);
            head = head->next;
        }
        int left = 0;
        int right = ret.size() - 1;
        while (left < right) {
            int tmp = ret[left];
            ret[left] = ret[right];
            ret[right] = tmp;
            left++;
            right--;
        }
        return ret;
    }
};