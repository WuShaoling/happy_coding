#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] ||  // left
                 rec1[3] <= rec2[1] ||  // bottom
                 rec1[0] >= rec2[2] ||  // right
                 rec1[1] >= rec2[3]);   // top
    }
};

int main() {
    Solution s;
    vector<int> v1 = {4, 4, 14, 7};
    vector<int> v2 = {4, 3, 8, 8};
    cout << s.isRectangleOverlap(v1, v2);
}