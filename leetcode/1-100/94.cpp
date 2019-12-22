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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode *> s;
        TreeNode *p = root;

        while (p != NULL || !s.empty()) {
            while (p != NULL) {
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                TreeNode *t = s.top();
                res.push_back(t->val);
                s.pop();
                p = p->right;
            }
        }

        return res;
    }
};

// class Solution {
//    public:
//     vector<int> inorderTraversal(TreeNode *root) {
//         traversal(root);
//         return res;
//     }

//     void traversal(TreeNode *root) {
//         if (root) {
//             traversal(root->left);
//             res.push_back(root->val);
//             traversal(root->right);
//         }
//     }

//    private:
//     vector<int> res;
// };

int main() {}