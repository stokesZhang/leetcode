#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int sum = 1000000;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i ++) {
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int temp = nums[i] + nums[l] + nums[r];
            if (abs(sum - target) > abs(temp - target)) {
                sum = temp;
            }
            if (temp == target) break;
            if (temp > target) r--;
            if (temp < target) l++;
        }
    }
    cout << sum << endl;
}