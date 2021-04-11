#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int trap = 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    while (left < right) {  // 左指针和右指针永远有一个处于left/right_max上
        if (height[left] < height[right]) { // 左指针指的要么是left_max，否则left_max比right_max小
            if (height[left] >= left_max) left_max = height[left];
            else trap += left_max - height[left];
            left++;
        } else {
            if (height[right] >= right_max) right_max = height[right];
            else trap += right_max - height[right];
            right--; 
        }
    }
    // int l = 0;
    // while (l < n - 1) {
    //     int hightest = 0;
    //     for (int r = l + 1; r < n; r++) {
    //         hightest = max(hightest, height[r]);
    //         if (height[r] >= height[l]) {
    //             for (int i = l + 1; i < r; i++) {
    //                 trap += (height[l] - height[i]);
    //             }
    //             l = r;
    //             break;
    //         }
    //     }
    //     if (hightest < height[l]) height[l] = hightest;
    // }
    cout << trap << endl;
}