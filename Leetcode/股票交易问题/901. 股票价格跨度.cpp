// 编写一个 StockSpanner 类，它收集某些股票的每日报价，并返回该股票当日价格的跨度。

// 今天股票价格的跨度被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。

// 例如，如果未来7天股票的价格是 [100, 80, 60, 70, 60, 75, 85]，那么股票跨度将是 [1, 1, 1, 2, 1, 4, 6]。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/online-stock-span
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// Solution： 这里是要求小于等于今天的连续天数，并且从今天开始，所以其实比较重要的是前一天。 所以可以考虑使用单调栈
// 栈从大到小的顺序，
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int ret = 1;
        while (!prices.empty() && prices.top() <= price) {
            ret += weights.top();
            prices.pop();
            weights.pop();
        }

        prices.push(price);
        weights.push(ret);
        return ret;
    }
private:
    stack<int> weights;
    stack<int> prices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

