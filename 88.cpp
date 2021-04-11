#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2, 5, 6};
    int m = 3, n = 3;
    int p1 = m - 1, p2 = n - 1;
    int p = m + n - 1;
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p--;
        p2--;
    }
    for (auto &c : nums1)
        cout << c << " ";
    cout << endl;
}