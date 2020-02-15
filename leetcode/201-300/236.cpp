#include <iostream>
#include <map>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parentMap[root] = NULL;
        setParent(root->left, root);
        setParent(root->right, root);

        // 保存 p 的 parent
        map<TreeNode*, int> parent_p;
        TreeNode* t = p;
        while (t) {
            parent_p[t] = 1;
            t = parentMap[t];
        }

        // 在 p 的 parent 中查找 q 及 q 的 parent
        t = q;
        while (t) {
            if (parent_p.find(t) != parent_p.end()) return t;
            t = parentMap[t];
        }

        return root;
    }

    void setParent(TreeNode* cur, TreeNode* parent) {
        if (!cur) return;
        parentMap[cur] = parent;
        setParent(cur->left, cur);
        setParent(cur->right, cur);
    }

    map<TreeNode*, TreeNode*> parentMap;
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    cout << s.lowestCommonAncestor(root, root->left, root->right)->val;
}