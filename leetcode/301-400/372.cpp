#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int superPow(int a, vector<int>& b) {
        // if (b.size() == 0) return 1;

        // int last = b.back();
        // b.pop_back();

        // int part1 = qPow(a, last);
        // int part2 = qPow(superPow(a, b), 10);

        // return (part1 * part2) % base;

        int res = 1;
        for (int x : b) {
            res = qPow(res, 10) * qPow(a, x) % 1337;
        }
        return res;
    }

   private:
    int base = 1337;

    int myPow(int a, int k) {
        a %= base;
        int res = 1;
        for (int _ = 0; _ < k; _++) {
            res *= a;
            res %= base;
        }
        return res;
    }

    int qPow(int a, int k) {
        if (k == 0) return 1;
        if (k == 1) return a % base;

        a %= base;
        int res = qPow(a, k >> 1);
        res = (res % base) * (res % base) % base;

        if (k & 1) return (res * a) % base;
        return res;
    }
};

// a^1234 = a^4 * (a^123)^10

// a^123 = a^3 * (a^12)^10

// (a*b)%k = (a%k)*(b%k)%k

int main() {}