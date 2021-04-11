#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = -1, right = 0;
    int sum = 0;
    int ans = 1 << 20;
    while (right < n) {
        while (sum < target && right < n) {
            sum += nums[right];
            right++;
        }
        if (sum < target) break;
        while (sum >= target) {
            left++;
            sum -= nums[left];
        }
        ans = min(ans, right - left);
    }
    return (left >= 0) ? ans : 0;
}

int minSubArrayLen2(int target, vector<int> &nums) { // 双指针的另一种写法
    int n = nums.size();
    int ans = INT_MAX;
    int start = 0, end = 0;
    int sum = 0;
    while (end < n) {
        sum += nums[end];
        while (sum >= target) {
            ans = min(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        end++; // 每次循环结束时 end 向后移动一个位置
    }
    return ans == INT_MAX ? 0 : ans;
}

int minSubArrayLen3(int target, vector<int> &nums) {
    int n = nums.size();
    vector<int> sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + nums[i-1];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int s = target + sum[i - 1];
        auto bound = lower_bound(sum.begin(), sum.end(), target); // 库和函数来为我们实现这里二分查找大于等于某个数的第一个位置的功能
        if (bound != sum.end()) {
            ans = min(ans, static_cast<int>((bound - sum.begin()) - (i - 1)));
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

    int main()
{
    int s = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int ans = minSubArrayLen(s, nums);
    cout << ans << endl;
}