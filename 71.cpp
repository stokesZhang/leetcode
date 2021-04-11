#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string simplifyPath(string path) {
    vector<string> st;
    string s;
    stringstream tokenStream(path);
    while (getline(tokenStream, s, '/')) { // 使用stringstream 和 getline分割字符串
        if (s == ".." && !st.empty()) {
            st.pop_back();
        } else if (s != "." && s != "" && s != "..") {
            st.push_back(s);
        }
    }
    if (st.empty()) {
        return "/";
    }
    string ans;
    for (auto &s : st) {
        ans += "/";
        ans += s;
    }
    return ans;
}

int main() {
    string path = "/a/./b/../../c/";
    string ans = simplifyPath(path);
    cout << ans << endl;
}