#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(const vector<int> &v1, const vector<int> &v2) {
    return v1.size() > v2.size();
}

class Solution {
   public:
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        vector<int> path;
        helper(root, expectNumber, path);
        sort(res.begin(), res.end(), compare);
        return res;
    }

    void helper(TreeNode *root, int expectNumber, vector<int> path) {
        if (!root) return;

        path.push_back(root->val);
        expectNumber -= root->val;

        if (!root->left && !root->right) {
            if (expectNumber == 0) {
                res.push_back(path);
            }
            return;
        }

        helper(root->left, expectNumber, path);
        helper(root->right, expectNumber, path);
    }

    vector<vector<int> > res;
};

int main() {}