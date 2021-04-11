#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int m = s1.length(), n = s2.length();
    if (m + n != s3.length()) return false;
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    dp[0][0] = 1;
    vector<int> a;

    for (int i = 0; i < m; ++i) {
        if (s1[i] != s3[i]) break;
        dp[i+1][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (s2[i] != s3[i]) break;
        dp[0][i+1] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1])) {
                dp[i][j] = 1;
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    bool ans = isInterleave(s1, s2, s3);
    cout << ans << endl;
}