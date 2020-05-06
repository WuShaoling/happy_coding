#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int numTrees(int n) {
        /*
        C(0) = 1;  n == 0
        C(n) = (4*n-2) / (n+2) * C(n-1); n > 0
        */
        long c = 1;
        for (int i = 1; i <= n; i++) {
            c = c * (4 * i - 2) / (i + 1);
        }
        return c;
    }
};

int main() {}