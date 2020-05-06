#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;

        if (k == 0) return res;

        if (shorter == longer) {
            res.push_back(k * shorter);
            return res;
        }

        for (int i = 0; i <= k; i++) {
            res.push_back(shorter * (k - i) + i * longer);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> res = s.divingBoard(1, 2, 1);
    for (int i : res) cout << i << " ";
}