#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> dp;
vector<vector<string>> ans;
vector<string> tmp;
int n;

void dfs(string &s, int start) {
    if (start == n) {
        ans.push_back(tmp);
        return;
    }
    for (int i = start; i < n; ++i) {
        if (dp[start][i]) {
            tmp.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    n = s.length();
    dp.assign(n, vector<int>(n));
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            } else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
    }
    dfs(s, 0);
    return ans;
}

int main() {
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (auto &v : ans) {
        for (auto &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}