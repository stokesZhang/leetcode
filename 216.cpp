#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

// void dfs(int start, int sum, int k) {
//     if (sum < 0) {
//         return;
//     } else if (temp.size() == k) {
//         if (sum == 0) {
//             ans.push_back(temp);
//         }
//         return;
//     }
//     for (int i = start; i <= 10 - k + temp.size(); i ++) {
//         temp.push_back(i);
//         dfs(i+1, sum - i, k);
//         temp.pop_back();
//     }
// }

void dfs(int cur, int sum, int k) {
    if (temp.size() + 10 - cur < k || sum < 0) {
        return;
    }
    if (temp.size() == k) {
        if (sum == 0) {
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(cur);
    dfs(cur + 1, sum - cur, k);
    temp.pop_back();
    dfs(cur + 1, sum, k);
}

int main() {
    int k = 3, n = 9;
    dfs(1, n, k);
    for (auto &v : ans) {
        for (auto &c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
}