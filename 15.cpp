#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
双指针
*/

int main(int argc, char const *argv[]) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // 跳过重复的第一个数
        int l = i + 1;  // 变为双指针two-sum问题
        int r = nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                vector<int> temp = {nums[i], nums[l], nums[r]};
                ans.push_back(temp);
                while (l < r && nums[l] == nums[l+1]) l++;  // 跳过第二，第三个数重复的情况
                while (l < r && nums[r] == nums[r-1]) r--; 
                l++; // 因为这两个指针的值为边界的情况考虑过了，不可能再继续作为边界，因此跳过
                r--;
            }
            else if (sum > 0) r--; // 和超了，因此要减小大的值
            else if (sum < 0) l++; // 和不够，因此要增加小的值
        }
    }
    for (auto &v: ans) {
        for (auto &c: v) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
