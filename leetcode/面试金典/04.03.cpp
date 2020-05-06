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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        vector<ListNode *> res;
        if (!tree) return res;

        queue<TreeNode *> *q = new queue<TreeNode *>();
        q->push(tree);
        while (!q->empty()) {
            ListNode *line = new ListNode(0);
            ListNode *p = line;
            int len = q->size();
            for (int i = 0; i < len; i++) {
                TreeNode *t = q->front();
                q->pop();
                if (t->left) q->push(t->left);
                if (t->right) q->push(t->right);

                p->next = new ListNode(t->val);
                p = p->next;
            }

            res.push_back(line->next);
        }

        return res;
    }
};

int main() {}