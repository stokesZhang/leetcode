#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    int need[128] = {0}, have[128] = {0};
    int len = 1 << 20, start = -1;
    int toMatch = 0;
    for (auto &c : t) {
        if (need[c] == 0) toMatch++;
        need[c]++;
    }
    int left=0, right=0;
    while (right < s.length()) {
        while (right < s.length() && toMatch > 0) {
            if (++have[s[right]] == need[s[right]]) toMatch--;
            right++;
        }
        while (toMatch == 0) {
            if (--have[s[left]] < need[s[left]]) toMatch++;
            left++;
        }
        if (right - left + 1 < len) {
            start = left - 1;
            len = right - left + 1;
        }
    }
    return (start < 0) ? "" : s.substr(start, len);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    string ans = minWindow(s, t);
    cout << ans << endl;
}