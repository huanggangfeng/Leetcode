// https://leetcode-cn.com/problems/sort-list/

// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

// 进阶：

// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sort-list
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        return  mergeSort(head);
    }

     ListNode* mergeSort(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *fast = head->next;
        ListNode *slow = head;  
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *L2 = slow->next;
        slow->next = NULL;
        head = mergeSort(head);
        L2 = mergeSort(L2);
        return mergeTwoList(head, L2);
     }

     ListNode* mergeTwoList(ListNode *L1, ListNode *L2) {
         ListNode *dummyHead = new ListNode;
         ListNode *tail = dummyHead;
         while (L1 != NULL && L2 != NULL) {
             if (L1->val <= L2->val) {
                 tail->next = L1;
                 L1 = L1->next;
                 tail = tail->next;
             } else {
                 tail->next = L2;
                 L2 = L2->next;
                 tail = tail->next;
             }
         }

         while (L1 != NULL) {
             tail->next = L1;
             L1 = L1->next;
             tail = tail->next;
         }

        while (L2 != NULL) {
             tail->next = L2;
             L2 = L2->next;
             tail = tail->next;
        }

        return dummyHead->next;
     }
};