#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &nums){
    int n = nums.size();
    vector<int> maxF(nums), minF(nums);
    for (int i = 1; i < n; ++i) {
        maxF[i] = max(maxF[i-1] * nums[i], max(minF[i-1] * nums[i], nums[i]));
        minF[i] = min(maxF[i - 1] * nums[i], min(minF[i - 1] * nums[i], nums[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
}

int main() {
    vector<int> nums = {2,3,-2,4};
    int ans = maxProduct(nums);
    cout << ans << endl;
}