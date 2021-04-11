#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
创建哈希表能够在O(1)时间内找到值为target - nums[i]的元素的位置
*/

int main(int argc, char const *argv[]) {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> ans;
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = hashtable.find(target - nums[i]); // 查找键值为target - nums[i]的元素
        if (it != hashtable.end()) {
            ans.push_back(i);
            ans.push_back(it->second);
            break;
        }
        hashtable[nums[i]] = i;
    }
    for (auto &v : ans)
        cout << v << endl;
    return 0;
}
