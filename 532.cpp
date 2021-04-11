#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findPairs(vector<int> &nums, int k) {
    if (k < 0) return 0;
    int count = 0;
    unordered_map<int, int> num_cnt;
    for (auto &v : nums) {
        num_cnt[v]++;
    }
    for (auto &m : num_cnt) {
        if (k == 0 && m.second > 1) {
            count++;
        } else if (k > 0) {
            count += num_cnt.count(m.first + k);
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1,2,4,4,3,3,0,9,2,3};
    int k = 3;
    int ans = findPairs(nums, k);
    cout << ans << endl;
}