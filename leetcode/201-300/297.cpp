#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   public:
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp) {
                out << temp->val << " ";
                q.push(temp->left);
                q.push(temp->right);
            } else {
                out << "null ";
            }
        }

        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream input(data);
        vector<TreeNode*> nodes;
        string val;
        while (input >> val) {
            if (val == "null") {
                nodes.push_back(NULL);
            } else {
                nodes.push_back(new TreeNode(std::stoi(val)));
            }
        }

        int j = 1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == NULL) continue;
            if (j < nodes.size()) nodes[i]->left = nodes[j++];
            if (j < nodes.size()) nodes[i]->right = nodes[j++];
        }
        return nodes[0];
    }
};

int main() {}