#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    int n = s1.length();
    int dp[n][n][n + 1]; // s1下标，s2下标，长度
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j][1] = (s1[i] == s2[j]);
        }
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i + l <= n; ++i) {
            for (int j = 0; j + l <= n; ++j) {
                dp[i][j][l] = 0;
                for (int k = 1; k < l; ++k) {
                    if (((dp[i][j][k] == 1) && (dp[i+k][j+k][l-k] == 1)) || ((dp[i][j+l-k][k] == 1) && (dp[i+k][j][l-k] == 1))) {
                        dp[i][j][l] = 1;
                    }
                }
            }
        }
    }
    return dp[0][0][n];
}

int main() {
    string s1 = "abcde", s2 = "caebd";
    bool ans = isScramble(s1, s2);
    cout << ans << endl;
}