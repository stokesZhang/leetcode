#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> occ;
    int ans = 0;
    int n = s.length();
    int right = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            occ.erase(s[i - 1]);
        }
        while (right < n && occ.count(s[right]) == 0) {
            occ.insert(s[right]);
            right++;
        }
        ans = max(ans, right - i);
    }
    return ans;
}

int main() {
    string s = "pwwkew";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}