#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words) {
    unordered_map<string, int> wordcnt;
    for (auto &s : words) {
        wordcnt[s]++;
    }
    int len = words[0].length();
    vector<int> ans;

    for (int i = 0; i < len; i++) {
        int left = i, right = left;
        int cnt = 0;

        unordered_map<string, int> window;
        while(left + words.size() * len <= s.size()) {
            string temp;
            while (cnt < words.size()) {
                temp = s.substr(right, len);
                if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) { // 没找到这个词或者这个词出现的次数超过了字典中次数
                    break;
                } else {
                    window[temp]++;
                    cnt++;
                    right += len;
                }
            }
            if (cnt == words.size()) {
                ans.push_back(left);
            }
            if (wordcnt.find(temp) != wordcnt.end()) { // 是因为超出字典中次数而退出的，因此窗口只移动一个词的大小
                window[s.substr(left, len)]--;
                cnt--;
                left += len;
            } else {
                cnt = 0;
                window.clear();
                right += len;
                left = right;
            }
        }
    }
    return ans;
}

int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> ans = findSubstring(s, words);
    for (auto &c : ans) {
        cout << c << " ";
    }
    cout << endl;
}