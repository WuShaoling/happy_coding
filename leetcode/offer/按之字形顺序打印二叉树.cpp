#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;

        if (!pRoot) return res;

        queue<TreeNode*>* q1 = new queue<TreeNode*>();
        queue<TreeNode*>* q2 = new queue<TreeNode*>();
        q1->push(pRoot);
        bool flag = false;
        while (!q1->empty()) {
            vector<int> line;
            while (!q1->empty()) {
                TreeNode* t = q1->front();
                q1->pop();

                line.push_back(t->val);
                if (t->left) q2->push(t->left);
                if (t->right) q2->push(t->right);
            }
            if (flag) reverse(line.begin(), line.end());
            res.push_back(line);

            queue<TreeNode*>* t = q1;
            q1 = q2;
            q2 = t;
            flag = !flag;
        }

        return res;
    }
};

int main() {}