#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int min_buy = 1 << 20;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        min_buy = min(min_buy, prices[i]);
        ans = max(ans, prices[i] - min_buy);
    }
    return ans;
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << ans << endl;
}