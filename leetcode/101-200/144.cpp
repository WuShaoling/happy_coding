#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode *> s;
        TreeNode *p = root;

        while (p != NULL || !s.empty()) {
            while (p != NULL) {
                res.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }

        return res;
    }
};

int main() {}