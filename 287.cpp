#include <iostream>
#include <vector>

using namespace std;

//二分查找
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 1, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += nums[i] <= mid;
        }
        if (cnt <= mid) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

// 快慢指针, Floyd 判圈算法, 对nums[]数组建图，每个位置i连一条 i->nums[i]的边，存在的重复的数字target，因此 target这个位置一定有起码两条指向它的边，因此整张图一定存在环，两条指向它的边说明这个点是进入环的那个点
int findDuplicate2(vector<int>& nums) {
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> nums = {1,3,4,2,2};

}