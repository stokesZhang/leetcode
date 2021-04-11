#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s2.length() < s1.length()) return false;
    vector<int> Cnt(26);
    vector<int> now(26);
    int toMatch = 0;
    for (auto &c : s1) {
        if (Cnt[c-'a'] == 0) {
            toMatch++;
        }
        Cnt[c-'a']++;
    }
    int left = 0, right = 0;
    int n = s2.length();
    while(right < n) {
        now[s2[right]-'a']++;
        if (now[s2[right]-'a'] == Cnt[s2[right]-'a']) {
            toMatch--;
        }
        right++;
        if (right - left == s1.length()) {
            if (toMatch == 0) {
                return true;
            } else {
                if (now[s2[left]-'a'] == Cnt[s2[left]-'a']) {
                    toMatch++;
                }
                now[s2[left] - 'a']--;
                left++;
            }
        }
    }
    return false;
}

int main() {
    string s1 = "trinitrophenylmethylnitramine", s2 = "dinitrophenylhydrazinetrinitrophenylmethylnitramine";

    bool ans = checkInclusion(s1, s2);
    cout << ans << endl;
}