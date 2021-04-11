#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    int len = T.size();
    vector<int> ans(len);
    stack<int> st;
    for (int i = 0; i < len; ++i) {
        while (!st.empty() && T[st.top()] < T[i]) {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temperatures);
    for (auto &c : ans) {
        cout << c << endl;
    }
}