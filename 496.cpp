/*
单调栈的根本作用在于求得「每一个数字在原始序列中左/右边第一个大于/小于它自己的数字」，每个数字只会入栈一次且最多出栈一次
一次「单调递增栈」的过程，可以求得每个数字左边第一个小于等于它的数，以及右边第一个小于它的数
*/
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    stack<int> st;
    for (int i = 0; i < nums2.size(); ++i) {
        while (!st.empty() && st.top() < nums2[i]) {
            map[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }
    while (!st.empty()) {
        map[st.top()] = -1;
        st.pop();
    }
    vector<int> ans(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
        ans[i] = map[nums1[i]];
    }
    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (auto &c : ans) {
        cout << c << endl;
    }
}