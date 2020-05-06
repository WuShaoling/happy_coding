#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int exchangeBits(int num) {
        //奇数
        int odd = num & 0x55555555;
        //偶数
        int even = num & 0xaaaaaaaa;
        odd = odd << 1;
        even = even >> 1;
        return odd | even;
    }
};

int main() {
    Solution s;
    cout << s.exchangeBits(3);
}