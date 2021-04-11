#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n);
    int rob_head = 0, rob_tail = 0;
    
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; ++i) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    rob_head = dp[n - 2];

    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    rob_tail = dp[n - 1];
    return max(rob_head, rob_tail);
}

int main() {
    vector<int> nums = {2, 3, 2};
    int ans = rob(nums);
    cout << ans << endl;
}