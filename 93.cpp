#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ans;
vector<int> segments;

void dfs(int segId, int segStart, string &s) {
    if (segId == 4) {
        if (segStart == s.length()) {
            string ipAddr;
            for (int i = 0; i < 4; i++) {
                ipAddr += to_string(segments[i]);
                if (i != 3) {
                    ipAddr += ".";
                }
            }
            ans.push_back(ipAddr);
        }
        return;
    }
    if (segStart == s.length()) {
        return;
    }
    if (s[segStart] == '0') {
        segments[segId] = 0;
        dfs(segId + 1, segStart + 1, s);
        return;
    }
    int addr = 0;
    for (int i = segStart; i < s.length(); i++) {
        addr = addr*10 + s[i] - '0';
        if (addr > 0 && addr <= 255) {
            segments[segId] = addr;
            dfs(segId + 1, i + 1, s);
        } else {
            break;
        }
    }
    
}

vector<string> restoreIpAddresses(string s) {
    segments.resize(4);
    dfs(0, 0, s);
    return ans;
}

int main() {
    string s = "25525511135";
    vector<string> ans = restoreIpAddresses(s);
    for (auto &s : ans) {
        cout << s << endl;
    }
}