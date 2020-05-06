#include <iostream>
#include <queue>
#include <sstream>
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
        queue<TreeNode*> q;
        q.push(root);
        ostringstream out;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp) {
                out << "null ";
            } else {
                out << to_string(temp->val) << " ";
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        istringstream in(data);
        vector<TreeNode*> nodes;
        string temp;
        while (in >> temp) {
            if (temp != "null") {
                nodes.push_back(new TreeNode(std::stoi(temp)));
            } else {
                nodes.push_back(NULL);
            }
        }
        int j = 1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == NULL) continue;
            if (j < nodes.size()) {
                nodes[i]->left = nodes[j++];
            }
            if (j < nodes.size()) {
                nodes[i]->right = nodes[j++];
            }
        }
        return nodes[0];
    }
};

int main() {}