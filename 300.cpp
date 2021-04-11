#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS1(vector<int>& nums) { // O(n^2)复杂度
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxlen = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}

int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> d;  // d[i] 表示长度为i+1的最长上升子序列的末尾元素的最小值
    d.push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
        if (nums[i] > d.back()) {
            d.push_back(nums[i]);
        } else {
            int left = 0, right = d.size() - 1;
            while (left < right) { // 二分查找比nums[i]小的第一个数
                int mid = (left + right) / 2;
                if (d[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            d[left] = nums[i];
        }
    }
    return d.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = lengthOfLIS2(nums);
    cout << ans << endl;
}