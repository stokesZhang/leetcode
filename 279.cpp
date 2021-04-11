#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = i;
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], 1 + dp[i - j*j]);
        }
    }
    return dp[n];
}

int main() {
    int n = 12;
    int ans = numSquares(n);
    cout << ans << endl;
}