#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> in(n+1);
    vector<int> out(n+1);
    in[1] = -prices[0];
    for (int i = 1; i < n; ++i) {
        in[i+1] = max(in[i], out[i-1] - prices[i]);
        out[i+1] = max(out[i], in[i] + prices[i]);
    }
    return out[n];
}

int maxProfit2(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int n = prices.size();
    int f0 = -prices[0];    // 表示当前（当天结束之后）持有股票
    int f1 = 0;     // 表示当前没有股票且处于冷冻期
    int f2 = 0;     // 表示当前没有股票且不处于冷冻期
    for (int i = 1; i < n; ++i) {
        tie(f0, f1, f2) = make_tuple(max(f0, f2 - prices[i]), f0 + prices[i], max(f1, f2)); // 相当于python里的()
    }

    return max(f1, f2);
}

int main() {
    vector<int> prices = {1,2,3,0,2};
    int ans = maxProfit(prices);
    cout << ans << endl;
}