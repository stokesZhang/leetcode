#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 20;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i - 1][j - 1];
        }
    }
    int minTotal = inf;
    for (int i = 1; i <= n; ++i) {
        minTotal = min(minTotal, dp[n][i]);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return minTotal;
}

int minimumTotal2(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(2, vector<int>(n + 1, inf));
    dp[1][1] = triangle[0][0];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i % 2][j] = min(dp[(i - 1) % 2][j - 1], dp[(i - 1) % 2][j]) + triangle[i - 1][j - 1];
        }
    }
    int minTotal = inf;
    for (int i = 1; i <= n; ++i) {
        minTotal = min(minTotal, dp[n % 2][i]);
    }
    return minTotal;
}

int minimumTotal3(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> f(n);
    f[0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        f[i] = f[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; --j) {
            f[j] = min(f[j - 1], f[j]) + triangle[i][j];
        }
        f[0] += triangle[i][0];
    }
    return *min_element(f.begin(), f.end());
}

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 6}, {4, 1, 8, 3}};
    int ans = minimumTotal2(triangle);
    cout << ans << endl;
}