#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);
        if (leaf1.size() != leaf2.size()) {
            return false;
        }
        for (int i = 0; i < leaf1.size(); i++) {
            if (leaf1[i] != leaf2[i]) {
                return false;
            }
        }
        return true;
    }

    void getLeaf(TreeNode *root, vector<int> &tree) {
        if (!root->left && !root->right) {
            tree.push_back(root->val);
            return;
        }
        if (root->left) {
            getLeaf(root->left, tree);
        }
        if (root->right) {
            getLeaf(root->right, tree);
        }
    }
};

int main() {
    Solution solution;

    cout << solution.leafSimilar(7);
}
