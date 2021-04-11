#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int maxSide = 0;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dp[0][i] = (matrix[0][i] == '1');
        maxSide = max(maxSide, dp[0][i]);
    }
    for (int i = 0; i < m; ++i) {
        dp[i][0] = (matrix[i][0] == '1');
        maxSide = max(maxSide, dp[i][0]);
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    int ans = maximalSquare(matrix);
    cout << ans << endl;
}