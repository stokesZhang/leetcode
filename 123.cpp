#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    /*在任意一天结束之后，我们会处于以下五个状态中的一种：
    - 未进行过任何操作；
    - 只进行过一次买操作；
    - 进行了一次买操作和一次卖操作，即完成了一笔交易；
    - 在完成了一笔交易的前提下，进行了第二次买操作；
    - 完成了全部两笔交易。*/
    //用buy1, sell1, buy2, sell2分别记录每一天结束时出于这四种状态的最大值
    int n = prices.size();
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < n; ++i) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
};

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int ans = maxProfit(prices);
    cout << ans << endl;
}