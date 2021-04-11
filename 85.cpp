#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;
    int row = matrix.size(), col = matrix[0].size();
    int ans = 0;
    vector<int> height(col, 0);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == '1') {
                height[j] += 1;
            } else {
                height[j] = 0;
            }
        }
        stack<int> st;
        vector<int> left(col, -1), right(col, col);
        for (int j = 0; j < col; ++j) {
            while(!st.empty() && height[st.top()] > height[j]) {
                right[st.top()] = j;
                st.pop();
            }
            if (!st.empty()) {
                left[j] = st.top();
            }
            st.push(j);
        }
        for (int j = 0; j < col; ++j) ans = max(ans, height[j]*(right[j] - left[j] - 1));
    }
    return ans;
}

int main() {
    vector<vector<char>> matrix {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
    int ans = maximalRectangle(matrix);
    cout << ans << endl;

}