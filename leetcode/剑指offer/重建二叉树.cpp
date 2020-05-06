#include <iostream>
#include <map>
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
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        map<int, int> mm;
        int i = 0;
        for (int v : vin) mm[v] = i++;
        return build(pre, vin, 0, pre.size(), mm);
    }

   private:
    int pre_root_index = 0;
    TreeNode* build(vector<int> pre, vector<int> vin, int in_left, int in_right,
                    map<int, int>& mm) {
        if (in_left >= in_right) return NULL;

        int root_val = pre[pre_root_index];
        pre_root_index++;
        int in_root_index = mm[root_val];

        TreeNode* root = new TreeNode(root_val);
        root->left = build(pre, vin, in_left, in_root_index, mm);
        root->right = build(pre, vin, in_root_index + 1, in_right, mm);
        return root;
    }
};

int main() {}