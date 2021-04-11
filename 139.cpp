#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict){
    int n = s.length();
    unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(n+1);
    dp[0] = true; // dp[i] 表示s的前i个字符能否由wordDict组合而成
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) { // 这里遍历前i-1个长度，如果记录最长和最短字符串长度可以加速遍历
            if (dp[j] == true && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool ans = wordBreak(s, wordDict);
    cout << ans << endl;
}