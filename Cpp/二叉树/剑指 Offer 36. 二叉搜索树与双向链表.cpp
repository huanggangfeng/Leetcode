// 剑指 Offer 36. 二叉搜索树与双向链表

// 若无空间限制，直接用数组保存

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        vector<Node*> nodes;
        inorderTraverse(root, nodes);
        int n = nodes.size();

        for (int i = 0; i < n; i++) {
            nodes[i]->left = nodes[(i + n - 1) % n];
            nodes[i]->right = nodes[(i + 1) % n];
        }
        return nodes[0];
    }

    void inorderTraverse(Node *root, vector<Node *> &nodes) {
        if (root == NULL)
            return;
        inorderTraverse(root->left, nodes);
        nodes.push_back(root);
        inorderTraverse(root->right, nodes);
    }
};

class Solution {
private:
    Node *previous = nullptr; // 纪录前一个遍历过的结点
    Node *last = nullptr; // 纪录第一个被遍历到的结点
    Node *first = nullptr; // 纪录最后一个遍历到的结点
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        inorderTraverse(root);
        // 让第一个结点和最后一个结点互指形成双向链表
        first->left = last;
        last->right = first;
        return first;
    }

    void inorderTraverse(Node *root) {
        if (root == nullptr)
            return;
        inorderTraverse(root->left);
        // 纪录第一个结点
        if (first == nullptr) {
            first = root;
        }
        // 当前和previous 结点相互指向对方，双向链表
        root->left = previous;
        if (previous != nullptr)
            previous->right = root;

        // 更新previes 结点, 为下一个遍历到的结点
        previous = root;
        // 更新遍历到的最后一个结点
        last = root;
        inorderTraverse(root->right);
    }
};

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/liang-chong-jie-fa-du-jian-dan-yi-dong-kan-wan-di-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。