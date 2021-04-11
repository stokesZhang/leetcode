#include <iostream>
#include <vector>
using namespace std;

int getnext(vector<int>& nums, int i) {
    int n = nums.size();
    return (((i + nums[i]) % n) + n) % n;
}

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i ++) {
        if (nums[i] == 0) {
            continue;
        }
        int slow = i, fast = i;
        do {
            slow = getnext(nums, slow);
            fast = getnext(nums, getnext(nums, fast));
            if (slow == fast) {
                if (slow == getnext(nums, slow)) {
                    break;
                } else return true;
            }
        } while (nums[i] * nums[fast] > 0 && nums[i] * nums[getnext(nums, fast)] > 0);
        slow = i;
        while (slow != i) {
            int next = getnext(nums, slow);
            nums[slow] = 0;
            slow = next;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {2,-1,1,2,2};
    bool ans = circularArrayLoop(nums);
    cout << ans << endl;
}