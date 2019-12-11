#include <iostream>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode *> *q1 = new queue<TreeNode *>();
        queue<TreeNode *> *q2 = new queue<TreeNode *>();
        q1->push(root);

        bool flag = true;

        while (!q1->empty()) {
            vector<int> temp;

            while (!q1->empty()) {
                TreeNode *t = q1->front();
                q1->pop();
                if (t->left) q2->push(t->left);
                if (t->right) q2->push(t->right);
                temp.push_back(t->val);
            }
            queue<TreeNode *> *tq = q1;
            q1 = q2;
            q2 = tq;

            if (!flag) reverse(temp.begin(), temp.end());
            res.push_back(temp);
            flag = !flag;
        }

        return res;
    }
};

int main() {}