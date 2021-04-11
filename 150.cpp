#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (auto const &s : tokens) {
        if (s == "+") {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            st.push(x + y);
        } else if (s == "-") {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            st.push(y - x);
        } else if (s == "*") {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            st.push(x * y);
        } else if (s == "/") {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            st.push(y / x);
        } else {
            st.push(stoi(s));
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    int ans = evalRPN(tokens);
    cout << ans << endl;
}