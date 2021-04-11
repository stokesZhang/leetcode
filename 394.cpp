#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getDigits(string &s, size_t &ptr) {
    string ret = "";
    while (isdigit(s[ptr])) {
        ret.push_back(s[ptr++]);
    }
    return ret;
}

string getString(vector <string> &v) {
    string ret;
    for (const auto &s: v) {
        ret += s;
    }
    return ret;
}

string decodeString(string s) {
    vector<string> st;
    size_t ptr = 0;
    while (ptr < s.length()) {
        char cur = s[ptr];
        if (isdigit(cur)) {
            string digits = getDigits(s, ptr);
            st.push_back(digits);
        } else if (isalpha(cur) || cur == '[') {
            st.push_back(string(1, s[ptr++]));
        } else {
            ++ptr;
            vector<string> sub;
            while (st.back() != "[") {
                sub.push_back(st.back());
                st.pop_back();
            }
            reverse(sub.begin(), sub.end());
            st.pop_back(); // 左括号出栈
            int repTime = stoi(st.back());
            st.pop_back();
            string t, o = getString(sub);
            while (repTime--) {
                t += o;
            }
            st.push_back(t);
        }
    }
    return getString(st);
}

int main() {
    string s = "3[a2[c]]";
    string ans = decodeString(s);
    cout << ans << endl;
}