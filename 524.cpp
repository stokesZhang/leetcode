#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isSubsequence(string x, string y) {
    int j = 0;
    for (int i = 0; j < x.length() && i < y.length(); i++) {
        if (x[j] == y[i]) {
            j++;
        }
    }
    return (j == x.length());
}

string findLongestWord(string s, vector<string>& d) {
    string max_ans = "";
    for (auto &str : d) {
        if (isSubsequence(str, s)) {
            if (max_ans.length() < str.length() || (max_ans.length() == str.length() && str < max_ans)) {
                max_ans = str;
            }
        }
    }
    return max_ans;
}

int main() {
    string s = "abpcplea";
    vector<string> d = {"ale","apple","monkey","plea"};
    string ans = findLongestWord(s, d);
    cout << ans << endl;
}