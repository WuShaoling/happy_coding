#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numberOf2sInRange(int n) {
        int ten = 1;
        int counts = 0;
        int cur, low, high;

        //  2000
        // 10000
        while (n / ten != 0) {
            cur = (n / ten) % 10;
            low = n % ten;
            high = n / (ten * 10);

            if (cur < 2) {
                counts += high * ten;
            } else if (cur == 2) {
                counts += high * ten + low + 1;
            } else if (cur > 2) {
                counts += (high + 1) * ten;
            }

            ten *= 10;
        }
        return counts;
    }
};

int main() {}