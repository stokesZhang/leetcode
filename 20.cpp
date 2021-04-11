#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    stack<char> st;
    for (auto c : s) {
        if (pairs.count(c)) {
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    string s = "()";
    bool ans = isValid(s);
    cout << ans << endl;
}