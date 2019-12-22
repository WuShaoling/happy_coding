#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

   private:
    void dfs(TreeNode* root, int h) {
        if (!root) return;

        if (!root->left && !root->right) {
            if (h > maxDepth) {
                res = root->val;
                maxDepth = h;
            }
            return;
        }

        dfs(root->left, h + 1);
        dfs(root->right, h + 1);
    }

    int maxDepth = -1;
    int res = 0;
};

// class Solution {
//    public:
//     int findBottomLeftValue(TreeNode *root) {
//         int res;

//         queue<TreeNode *> *q1 = new queue<TreeNode *>();
//         queue<TreeNode *> *q2 = new queue<TreeNode *>();
//         q1->push(root);

//         while (!q1->empty()) {

//             bool flag = true;
//             while (!q1->empty()) {
//                 TreeNode *t = q1->front();
//                 q1->pop();
//                 if (t->left) q2->push(t->left);
//                 if (t->right) q2->push(t->right);

//                 if (flag) {
//                     res = t->val;
//                     flag = false;
//                 }
//             }

//             queue<TreeNode *> *tq = q1;
//             q1 = q2;
//             q2 = tq;
//         }

//         return res;
//     }
// };

int main() {}