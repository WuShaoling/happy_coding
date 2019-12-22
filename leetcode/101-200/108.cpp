#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size());
    }

    TreeNode * buildBST(vector<int>& nums, int left, int right){
        if(left >= right)
            return NULL;
		int mid = (int)(left + right)/2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = buildBST(nums, left, mid);
		root->right = buildBST(nums, mid+1, right);
		return root;
    }
};

int main(){
}