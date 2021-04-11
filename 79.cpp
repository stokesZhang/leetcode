#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& s, int k) {
    if (board[i][j] != s[k]) {
        return false;
    } else if (k == s.length() - 1) {
        return true;
    }
    visited[i][j] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool result = false;
    for (const auto &dir : directions) {
        int new_i = i + dir.first;
        int new_j = j + dir.second;
        if (new_i >=0 && new_i < board.size() && new_j >=0 && new_j < board[0].size() && visited[new_i][new_j] == false) {
            bool flag = check(board, visited, new_i, new_j, s, k + 1);
            if (flag) {
                result = true;
                break;
            }
        }
    }
    visited[i][j] = false;
    return result;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "ABCB";
    int h = board.size(), w = board[0].size();
    vector<vector<bool>>  visited(h, vector<bool>(w));
    bool result = false;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool flag = check(board, visited, i, j, word, 0);
            if (flag) result = true;
        }
    }
    cout << result << endl;
}