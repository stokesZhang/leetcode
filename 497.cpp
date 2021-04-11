/*
单调栈的根本作用在于求得「每一个数字在原始序列中左/右边第一个大于/小于它自己的数字」，每个数字只会入栈一次且最多出栈一次
一次「单调递增栈」的过程，可以求得每个数字左边第一个小于等于它的数，以及右边第一个小于它的数
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int len = nums.size();
    nums.resize(2*len);
    for (int i = 0; i < len; ++i) {
        nums[i+len] = nums[i];
    }
    vector<int> ans(len, -1);
    for (int i = 0; i < 2*len; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            if (st.top() < len) ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> ans = nextGreaterElements(nums);
    for (auto &c : ans) {
        cout << c << endl;
    }
}