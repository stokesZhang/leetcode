#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool find132pattern(vector<int>& nums) {
    vector<int> mi(nums.size());
    mi[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        mi[i] = min(mi[i-1], nums[i]);
    }
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] > mi[i]) {
            while (!st.empty() && st.top() <= mi[i]) {
                st.pop();
            }
            if (!st.empty() && st.top() < nums[i]) {
                return true;
            }
            st.push(nums[i]);
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    bool ans = find132pattern(nums);
    cout << ans << endl;
}