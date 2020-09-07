/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/submissions/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;

        int lenA = 0;
        int lenB = 0;
        ListNode *p1 = headA;
        while (p1 != NULL) {
            lenA++;
            p1 = p1->next;
        }
        ListNode *p2 = headB;
        while (p2 != NULL) {
            lenB++;
            p2 = p2->next;
        }


        if (lenA >= lenB) {
            int x = lenA - lenB;
            while (x--) {
                headA = headA->next;
            }
        } else {
            int x = lenB - lenA;
            while (x--) {
                headB = headB->next;
            }
        }

        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

// Solution2: 不用计算两个链表长度，两个指针一次遍历
// 1. linA走到结尾的时候，把LINB 拼接到后面，
// 2. linB走到结尾的时候，把LINA 拼接到后面，
// 经过拼接，长度相等，所以如果有相同的的元素，一定能找打，要预防死循环

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;

        ListNode *p1 = headA;
        ListNode *p2 = headB;
        int i = 0;
        while (p1 != p2) {
            // 不会有死循环，即使没有相交结点，当走了lenA+lenB步后，p1-next和p2->next最后都会为null，p1和p2则相等
            p1 = (p1 == NULL)? headB : p1->next; // 当p1到headA的结尾时候，把它指向headB，这样p1最多走lenA+lenB步
            p2 = (p2 == NULL)? headA : p2->next; // 同上
            // 写成下面这样则会有死循环，因为p1/p2永远不会为NULL
            // p1 = (p1->next == NULL)? headB : p1->next; 
            // p2 = (p2->next == NULL)? headA : p2->next; 
        }
        return p1;
    }
};