#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    int n = heights.size();
    int ans = 0;
    stack<int> st; // 单调栈，单调递增
    vector<int> left(n), right(n, n);
    for (int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) { // 当遇到元素不单调时需pop出栈顶元素
            right[st.top()] = i;
            st.pop();
        }
        left[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }
    for (int i = 0; i < n ; i++) {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    // stack<pair<int, int>> st;
    // for (int i = 0; i < n; i++) {
    //     if (st.empty() || st.top().first < heights[i]) {
    //         pair<int, int> p{heights[i], 1};
    //         st.push(p);
    //     } else {
    //         int w = 0;
    //         while (!st.empty() && st.top().first >= heights[i]) {
    //             pair<int, int> p = st.top();
    //             w += p.second;
    //             st.pop();
    //             ans = max(ans, w * p.first);
    //         }
    //         pair<int, int> newp{heights[i], w+1};
    //         st.push(newp);
    //     }
    // }
    // int w = 0;
    // while (!st.empty()) {
    //     pair<int, int> p = st.top();
    //     w += p.second;
    //     st.pop();
    //     ans = max(ans, w * p.first);
    // }
    cout << ans << endl;
}