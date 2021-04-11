#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> G(n+1); // 长度为k的序列能构成的二叉树的个数
    //能构成的二叉树的个数仅与长度有关，与具体的序列内容无关
    G[0] = 1, G[1] = 1;
    for (int i = 2; i <= n; ++i) { //枚举长度
        for (int j = 1; j <= i; ++j) { // 根的位置
            G[i] += G[j-1] * G[i-j]; // 左子树长度为j-1，右子树长度为i-j
        } 
    }
    return G[n];
}

int main() {
    int n = 3;
    int ans = numTrees(n);
    cout << ans << endl;
}