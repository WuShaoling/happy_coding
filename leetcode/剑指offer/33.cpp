#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() <= 1) return true;

        return check(postorder, 0, postorder.size() - 1);
    }

    bool check(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;

        int root = postorder[right];
        int i = left;
        for (; i < right; i++) {
            if (postorder[i] > root) break;
        }

        for (int j = i + 1; j < right; j++) {
            if (postorder[j] < root) return false;
        }

        return check(postorder, left, i - 1) && check(postorder, i, right - 1);
    }
};

int main() {
    Solution s;
    vector<int> v = {6};
    cout << s.verifyPostorder(v);
}
/*
l     i r
1,3,2,6,5

    6
      7

      7 6
*/
