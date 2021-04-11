#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;
vector<int> path;
void back_tracking(vector<int>& nums, int start) {
    ans.push_back(path);
    for (auto &c : path) {
        cout << c << " ";
    }
    cout << endl;
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i-1]) continue; // 同层去重
        path.push_back(nums[i]);
        back_tracking(nums, i + 1);
        path.pop_back();
    }
}

int main() {
    vector<int> nums = {1,2,2};
    sort(nums.begin(), nums.end());
    back_tracking(nums, 0);
}