#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}                    
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        ldfs(root);
    }

    void ldfs(TreeNode *node) { // left dfs
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        ldfs(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(20);
    TreeNode* n4 = new TreeNode(15, n2, n3);
    TreeNode* root = new TreeNode(7, n1, n4);
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
}