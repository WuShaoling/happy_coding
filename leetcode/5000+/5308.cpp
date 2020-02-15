#include <iostream>

using namespace std;

class Solution {
   public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int ba = a & 1;
            int bb = b & 1;
            int bc = c & 1;
            if ((ba | bb) != bc) {
                res++;
                if (bc == 0 && (ba & bb)) res++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minFlips(1, 2, 3);
}