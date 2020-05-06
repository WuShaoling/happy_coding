#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int n1 = 1, n2 = 2, t;
        for (int i = 3; i <= n; i++) {
            t = n2;
            n2 += n1;
            n1 = t;
        }
        return n2;
    }
};

int main() {}