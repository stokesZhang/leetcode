#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums){
    if (nums.empty()) {
        return 0;
    }
    int n = nums.size();
    vector<int> dp(n+1);
    dp[1] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]); 
    }
    return dp[n];
}

int main() {
    vector<int> nums = {1,2,3,1};
    int ans = rob(nums);
    cout << ans << endl;
}