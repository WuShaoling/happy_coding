#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    int reverseBits(int num) {
        bitset<32> bit(num);

        int right[32];
        right[31] = 0;
        for (int i = 30; i >= 0; i--) {
            if (bit[i + 1] == 1) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 0;
            }
        }

        int res = 0;
        if (bit[0] == 0) res = right[0] + 1;

        int left = 0;
        for (int i = 1; i < 32; i++) {
            if (bit[i - 1] == 0)
                left = 0;
            else
                left += 1;

            if (bit[i] == 0) {
                res = max(res, left + right[i] + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits(1775);
}

// 012345
// 0012
// 011101