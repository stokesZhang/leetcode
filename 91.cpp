#include <iostream>
#include <string>
using namespace std;

int numDecodings(string s) {
    int n = s.length();
    int dp[n+1];
    dp[0] = 1;
    dp[1] = (s[0] != '0');
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] * (s[i-1] != '0');
        int tmp = 10 * (s[i-2] - '0') + (s[i-1] - '0');
        if (tmp <= 26 && tmp >= 10) {
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}

int numDecodings2(string s) {
    if (s[0] == '0') return 0;
    int last = 1, cur = 1;
    int n = s.length();
    for (int i = 1; i < n; ++i) {
        int tmp = cur;
        if (s[i] == '0') {
            if (s[i-1] == '1' || s[i-1] == '2') cur = last;
            else return 0;
        } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            cur = cur + last;
        }
        last = tmp;
    }
    return cur;
}

int main() {
    string s = "06";
    int ans = numDecodings2(s);
    cout << ans << endl;
}