#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans = nums[0];
    int maxSum = nums[0], n = nums.size();
    for (int i = 1; i < n; ++i) {
        maxSum = max(maxSum + nums[i], nums[i]);
        ans = max(ans, maxSum);
    }
    return ans;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(nums);
    cout << ans << endl;
}