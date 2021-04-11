#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> t;
    vector<vector<int>> ans;
    int n = nums.size();
    for (int mask = 0; mask < (1<<n); mask++) { // 利用掩码构造子集
        t.clear();
        for (int i = 0; i < n; i ++) {
            if (mask & (1<<i)) {
                t.push_back(nums[i]);
            }
        }
        ans.push_back(t);
    }
}