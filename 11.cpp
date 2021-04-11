#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
双指针法：需要移动两边的问题可以考虑双指针法
一开始，双指针指向数组的左右边界，每次将对应的数字较小的那个指针往另一个指针的方向移动一个位置，就表示我们认为这个指针不可能再作为容器的边界了。

双指针代表的是可以作为容器边界的所有位置的范围。在一开始，双指针指向数组的左右边界，表示数组中所有的位置都可以作为容器的边界，因为我们还没有进行过任何尝试。在这之后，我们每次将对应的数字较小的那个指针往另一个指针 的方向移动一个位置，就表示我们认为这个指针不可能再作为容器的边界了。
若保留这个指针，继续缩小边界范围，则容量一定减小
*/
int main(int argc, char const *argv[]) {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = height.size();
    int ans = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        ans = max(min(height[left], height[right]) * (right - left), ans);
        if (height[left] < height[right]) left++;
        else right--;
    }
    cout << ans << endl;
}
