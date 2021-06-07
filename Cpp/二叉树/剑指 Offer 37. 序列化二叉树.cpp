// https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
// 请实现两个函数，分别用来序列化和反序列化二叉树。

// 示例: 

// 你可以将以下二叉树：

//     1
//    / \
//   2   3
//      / \
//     4   5

// 序列化为 "[1,2,3,null,null,4,5]"

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        pre_serialize(root, ret);
        return ret;
    }

    void pre_serialize(TreeNode *root, string &ret) {
        if (root == NULL)
            return;
        // 每个元素后面加！分割， 然后空指针用#表示
        ret += to_string(root->val) + "!"; 
        if (root->left == nullptr)
            ret += "#!";
        else
            pre_serialize(root->left, ret);

        if (root->right == nullptr)
            ret += "#!";
        else
            pre_serialize(root->right, ret);  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        queue<string> q;
        string_split(data, q);

        return helper(q);
    }

    TreeNode *helper(queue<string> &q) {
        if (q.empty()) {
            return nullptr;
        }
        
        string tmp = q.front();
        q.pop();
        if (tmp == "#") 
            return nullptr;
        TreeNode *node = new TreeNode(atoi(tmp.c_str()));
        node->left = helper(q);
        node->right = helper(q);

        return node;
    }

    void string_split(string data, queue<string> &q) {
        int start_pos = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == '!') {
                string tmp = data.substr(start_pos, i - start_pos);
                q.push(tmp);
                start_pos = i + 1;
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));