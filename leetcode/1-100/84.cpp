#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct SegTreeNode {
    int start, end, minIndex;
    SegTreeNode *left, *right;
    SegTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        left = right = NULL;
    }
} * SegTree;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;

        SegTree root = buildSegTree(heights, 0, heights.size() - 1);
        return findMaxArea(heights, root, 0, heights.size() - 1);
    }

    int findMaxArea(vector<int>& heights, SegTree root, int start, int end) {
        if (start > end) return -1;
        if (start == end) return heights[start];
        int minIndex = query(root, heights, start, end);
        int leftMax = findMaxArea(heights, root, start, minIndex - 1);
        int rightMax = findMaxArea(heights, root, minIndex + 1, end);
        int curMaxArea = (end - start + 1) * heights[minIndex];
        return max(curMaxArea, max(leftMax, rightMax));
    }

    int query(SegTree root, vector<int>& heights, int start, int end) {
        if (!root || end < root->start || start > root->end) return -1;

        if (start == root->start && root->end == end) return root->minIndex;

        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) return query(root->left, heights, start, end);
        if (start >= mid + 1) return query(root->right, heights, start, end);

        int left = query(root->left, heights, start, mid);
        int right = query(root->right, heights, mid + 1, end);
        if (left == -1) return right;
        if (right == -1) return left;
        return heights[left] < heights[right] ? left : right;

        // int leftMin = query(root->left, heights, start, end);
        // int rightMin = query(root->right, heights, start, end);
        // if (leftMin == -1) return rightMin;
        // if (rightMin == -1) return leftMin;
        // return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
    }

    SegTree buildSegTree(vector<int>& heights, int start, int end) {
        if (start > end) return NULL;
        SegTree root = new SegTreeNode(start, end);
        if (start == end) {
            root->minIndex = start;
            return root;
        }

        int mid = start + (end - start) / 2;
        root->left = buildSegTree(heights, start, mid);
        root->right = buildSegTree(heights, mid + 1, end);
        root->minIndex =
            heights[root->left->minIndex] < heights[root->right->minIndex]
                ? root->left->minIndex
                : root->right->minIndex;
        return root;
    }
};

// class Solution {
//    public:
//     int largestRectangleArea(vector<int>& heights) {
//         return dc(heights, 0, heights.size() - 1);
//     }

//     int dc(vector<int>& heights, int left, int right) {  //[]
//         if (left > right) return 0;
//         if (left == right) heights[left];

//         int minIndex = left;
//         for (int i = left; i <= right; i++) {
//             if (heights[i] < heights[minIndex]) minIndex = i;
//         }

//         int leftArea = dc(heights, left, minIndex - 1);
//         int rightArea = dc(heights, minIndex + 1, right);
//         int area = (right - left + 1) * heights[minIndex];

//         return max(area, max(leftArea, rightArea));
//     }
// };

int main() {}