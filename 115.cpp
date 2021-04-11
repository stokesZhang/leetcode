#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numDistinct(string s, string t) {
    int m = s.length(), n = t.length();
    if (m < n) return 0;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        if (s[i] == t[0]) dp[i][0] = 1;
        if (i > 0) dp[i][0] += dp[i - 1][0];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = max(i + n - m, 1); j <= i && j < n; ++j) {
            dp[i][j] = (s[i] == t[j]) ? dp[i - 1][j - 1] + dp[i - 1][j] : dp[i - 1][j];
        }
    }
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[m - 1][n - 1];
}

int main() {
    string s = "babgbag", t = "bag";
    int ans = numDistinct(s, t);
    cout << ans << endl;
}