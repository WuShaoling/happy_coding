#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        vector<bool> visited(n, false);
        queue<int> q;

        // 从0节点开始判断
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int root = q.front();
            q.pop();
            // 判断左子树
            int left = leftChild[root];
            if (left != -1) {
                if (visited[left]) return false;
                visited[left] = true;
                q.push(left);
            }
            // 判断右子树
            int right = rightChild[root];
            if (right != -1) {
                if (visited[right]) return false;
                visited[right] = true;
                q.push(right);
            }
        }
        for (int i = 0; i < n; i++) {
            // 如果有左子树或右子树，但是没被访问，说明可以构建多棵树，返回false
            if (visited[i] == false &&
                (leftChild[i] != -1 || rightChild[i] != -1))
                return false;
        }
        return true;
    }
};

int main() {}