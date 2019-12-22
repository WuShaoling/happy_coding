#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int minDiffInBST(TreeNode *root) {
        vector<int> t;
        f(root, t);
        int min = INT_MAX;
        for (int i = 0; i < t.size() - 1; i++) {
            int temp = t[i + 1] - t[i];
            if (temp < min) {
                min = temp;
            }
        }
        return min;
    }

    void f(TreeNode *root, vector<int> &t) {
        if (!root)
            return;
        f(root->left, t);
        t.push_back(root->val);
        f(root->right, t);
    }
};

int main() {

    Solution solution;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    TreeNode *p = root;
    cout << solution.minDiffInBST(p);

    return 0;
}
