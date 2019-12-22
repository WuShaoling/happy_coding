#include <algorithm>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode *> *q = new queue<TreeNode *>();
        queue<TreeNode *> *tq = new queue<TreeNode *>();
        q->push(root);

        while (!q->empty()) {
            vector<int> layer;
            while (!q->empty()) {
                TreeNode *node = q->front();
                q->pop();
                if (node->left) tq->push(node->left);
                if (node->right) tq->push(node->right);
                layer.push_back(node->val);
            }
            res.push_back(layer);

            queue<TreeNode *> *temp = q;
            q = tq;
            tq = temp;
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};

int main() {}