#include <iostream>
#include <vector>
#include <string>
using namespace std;


int minCut(string s) {
    int n = s.length();
    vector<vector<int>> pal(n, vector<int>(n));
    vector<int> dp(n, 1 << 20);
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                pal[i][j] = 1;
            } else if (l == 1) {
                pal[i][j] = (s[i] == s[j]);
            } else {
                pal[i][j] = (s[i] == s[j] && pal[i + 1][j - 1]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (pal[0][i] == 1) {
            dp[i] = 0;
        } else {
            for (int j = 0; j < i; ++j) {
                if (pal[j + 1][i] == 1) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            } 
        }
        
    }
    return dp[n - 1];
}

int main() {
    string s = "aab";
    int ans = minCut(s);
    cout << ans << endl;
}