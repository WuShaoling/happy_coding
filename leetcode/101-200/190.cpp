#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        uint32_t t = 1 << 31;
        int i = 0;
        while (n) {
            if (n & t) res |= (1 << i);
            i++;
            n <<= 1;
        }
        return res;
    }
    // 110000
    //     11
    uint32_t reverseBits2(uint32_t n) {
        int res = 0;
        int count = 32;
        while (count) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
            count--;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits2(43261596);
}