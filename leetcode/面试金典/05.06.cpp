#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int convertInteger(int A, int B) {
        unsigned int a = A;
        unsigned int b = B;
        int res = 0;
        while (a != 0 || b != 0) {
            if (((a & 1) ^ (b & 1)) == 1) res++;
            a >>= 1;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convertInteger(1, 2);
}
