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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode *> *q = new queue<TreeNode *>();
        queue<TreeNode *> *tq = new queue<TreeNode *>();
        q->push(root);

        while (!q->empty()) {
            double sum = 0;
            int count = q->size();
            while (!q->empty()) {
                TreeNode *node = q->front();
                q->pop();
                if (node->left) tq->push(node->left);
                if (node->right) tq->push(node->right);
                sum += node->val;
            }
            res.push_back(sum / count);

            queue<TreeNode *> *temp = q;
            q = tq;
            tq = temp;
        }
        return res;
    }
};

int main() {}