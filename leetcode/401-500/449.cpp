#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string res = "";
        queue<TreeNode*>* q1 = new queue<TreeNode*>();
        queue<TreeNode*>* q2 = new queue<TreeNode*>();
        q1->push(root);
        while (!q1->empty()) {
            while (!q1->empty) {
                TreeNode* t = q1->front();
                res.append(to_string(t->val)).append("!");
                if(t->left) q2->push();
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {}
};

int main() {}