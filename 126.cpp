#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1 << 20;

int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordlist = {"hot", "dot", "dog", "lot", "log", "cog"};
    int startId = -1, endId = -1;
    for (int i = 0; i < wordlist.size(); i++) {
        if (wordlist[i] == beginWord) {
            startId = i;
        } else if (wordlist[i] == endWord) {
            endId = i;
        }
    }
    if (endId == -1) {
        cout << "No such path\n";
        return 0;
    } else if (startId == -1) {
        wordlist.push_back(beginWord);
        startId = wordlist.size() - 1;
    }
    int n = wordlist.size();
    vector<vector<int>> E(n); // 构建word对应的图
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            string s1 = wordlist[i], s2 = wordlist[j];
            int distance = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] != s2[i]) {
                    distance ++;
                }
            }
            if (distance == 1) {
                E[i].push_back(j);
                E[j].push_back(i);
            }
        }
    }

    vector<string> path;
    vector<vector<string>> ans;
    vector<int> cost(n, INF);
    queue<vector<int>> q;
    cost[startId] = 0;

    q.push(vector<int>{startId}); // bfs
    while (!q.empty()) { //因为距离为一，因此用queue即可
        vector<int> now = q.front();
        q.pop();
        int last = now.back();
        if (last == endId) {
            vector<string> tmp;
            for (int index : now) tmp.push_back(wordlist[index]);
            ans.push_back(tmp);
        } else {
            for (int i = 0; i < E[last].size(); i++) {
                int to = E[last][i];
                if (cost[last] + 1 <= cost[to]) {
                    cost[to] = cost[last] + 1;
                    vector<int> tmp(now);
                    tmp.push_back(to);
                    q.push(tmp);
                }
            }
        }
    }

    for (auto &v : ans) {
        for (auto &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}