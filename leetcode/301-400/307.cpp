#include <iostream>
#include <vector>

using namespace std;

typedef struct SegTreeNode {
    int start, end, sum;
    SegTreeNode *left, *right;
    SegTreeNode(int start, int end) : left(NULL), right(NULL) {
        this->start = start;
        this->end = end;
    }
} * SegTree;

class NumArray {
   public:
    NumArray(vector<int>& nums) {
        this->segTree = buildSegTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) { update(this->segTree, i, val); }

    int sumRange(int i, int j) { return sumRange(this->segTree, i, j); }

   private:
    SegTree buildSegTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        SegTree root = new SegTreeNode(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildSegTree(nums, start, mid);
        root->right = buildSegTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int update(SegTree root, int i, int val) {
        if (!root) return 0;
        if (i < root->start || root->end < i) return root->sum;
        if (root->start == root->end) {  //仅有一个节点
            if (root->start == i) root->sum = val;
            return root->sum;
        }
        root->sum = update(root->left, i, val) + update(root->right, i, val);
        return root->sum;
    }

    int sumRange(SegTree root, int start, int end) {
        if (!this->segTree) return 0;
        if (root->start == start && root->end == end) return root->sum;
        int mid = root->start + (root->end - root->start) / 2;

        if (end <= mid) return sumRange(root->left, start, end);
        if (start >= mid + 1) return sumRange(root->right, start, end);
        return sumRange(root->left, start, mid) +
               sumRange(root->right, mid + 1, end);
    }

    SegTree segTree;
};

int main() {}