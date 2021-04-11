#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 20;

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<int> dp(col, inf);
    dp[0] = 0;
    for (int i = 0; i < row; ++i) {
        dp[0] += grid[i][0];
        for (int j = 1; j < col; ++j) {
            dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
        }
    }
    return dp[col - 1];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int ans = minPathSum(grid);
    cout << ans << endl;
}