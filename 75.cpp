#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums) {
    int n = nums.size();
    int p0 = 0, p1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {  // 0后面是连续的1，如果1被交换到后面会导致错误，因此需要再把1交换到前面
            swap(nums[p0], nums[i]); // 可以保证在指针和i之间不包含某元素
            if (p0 < p1) {
                swap(nums[p1], nums[i]); // 要保障指针之前都排好序
            }
            p0++;
            p1++;
        } else if (nums[i] == 1) {
            swap(nums[p1], nums[i]);
            p1++;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    for (auto &c : nums) cout << c << " ";
    cout << endl;
}