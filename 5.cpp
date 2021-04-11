#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n));
    int maxlen = 1;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            if (s[i] != s[j]) {
                dp[i][j] = 0;
            } else {
                if (j - i < 3) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j] == 1 && j - i + 1 > maxlen) {
                maxlen = j - i + 1;
                start = i;
            }
        }
    }
    return s.substr(start, maxlen);
}

int main() {
    string s = "babad";
    string ans = longestPalindrome(s);
    cout << ans << endl;
}