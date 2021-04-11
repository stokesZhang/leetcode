#include <iostream>
#include <string>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> num(26);
    int n = s.length();
    int maxn = 0; // 窗口移动过程中出现过的最大的重复次数
    int left = 0, right = 0; // 记录窗口边界（不一定符合，但他们之间的距离记录了最长出现过的窗口大小）
    while (right < n) {
        num[s[right] - 'A']++;
        maxn = max(maxn, num[s[right] - 'A']); // 当更大的maxn出现时，会产生新的最大值
        if (right - left + 1 - maxn > k) {
            num[s[left] - 'A']--;
            left++;
        }
        right++;
    }
    return right - left; // 窗口大小非减
}

int main() {
    string s = "ABAB";
    int k = 2;
    int ans = characterReplacement(s, k);
    cout << ans << endl;
}