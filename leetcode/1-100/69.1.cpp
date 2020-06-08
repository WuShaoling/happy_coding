#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        long i = 1, j = x;
        while (true) {
            long mid = i + (j - i) / 2;
            long mid2 = mid * mid;
            if (mid2 == x) {
                return mid;
            } else if (mid2 > x) {
                if ((mid - 1) * (mid - 1) <= x) return mid - 1;
                j = mid - 1;
            } else {
                if ((mid + 1) * (mid + 1) > x) return mid;
                i = mid + 1;
            }
        }
        return i;
    }
};

int main() {}