// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// hash map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        unordered_map<Node*, Node*> Node_map;

        Node* cur = head;
        while (cur) {
            Node_map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            if (cur->next)
                Node_map[cur]->next = Node_map[cur->next];
            if (cur->random)
                Node_map[cur]->random = Node_map[cur->random];
            cur = cur->next;
        }

        return Node_map[head];
    }
};



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node *cur = head;
        // Step1: 每个结点克隆一个，串在元结点后面
        while (cur != NULL) {
            Node *dup = new Node(cur->val);
            dup->next = cur->next;
            cur->next = dup;
            cur = dup->next;
        }

        cur = head;
        // 对新创建的结点random指针赋值
        while (cur != NULL) {
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        Node *dupHead = head->next;
        Node *dupTail = head->next;
        cur = head;
        // 链表一拆为二
        while (cur != NULL) {
            cur->next = cur->next->next;
            cur = cur->next;
            if (dupTail->next != NULL) {
                dupTail->next = dupTail->next->next;
                dupTail = dupTail->next;
            }
        }
        return dupHead;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node *cur = head;
        while (cur) {
            Node *p = new Node(cur->val);
            p->next = cur->next;
            cur->next = p;
            cur = cur->next->next;
        }
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        Node *dupHead = head->next;
        Node *dupTail = head->next;
        while (cur) {
            cur->next = dupTail->next;
            cur = cur->next;
            if (cur) {
                dupTail->next = cur->next;
                dupTail = dupTail->next;
            }
        }
        return dupHead;
    }
};