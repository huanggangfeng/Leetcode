
// 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

// 示例 1：

// 输入: n = 3
// 输出: 6
// 示例 2：

// 输入: n = 9
// 输出: 45

们可以将判断是否为递归的出口看作 A && B 表达式中的 A 部分，递归的主体函数看作 B 部分。如果不是递归出口，则返回 \textit{True}True，并继续执行表达式 B 的部分，否则递归结束。当然，你也可以用逻辑运算符 || 给出类似的实现，这里我们只提供结合逻辑运算符 && 的递归实现。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/qiu-12n-lcof/solution/qiu-12n-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int sumNums(int n) {
        // 们可以将判断是否为递归的出口看作 A && B 表达式中的 A 部分，递归的主体函数看作 B 部分。如果不是递归出口，则返回 \textit{True}True，并继续执行表达式 B 的部分，否则递归结束。
        // 当然，你也可以用逻辑运算符 || 给出类似的实现，这里我们只提供结合逻辑运算符 && 的递归实现。
        n && (n += sumNums(n-1));
        return n;
    }
};