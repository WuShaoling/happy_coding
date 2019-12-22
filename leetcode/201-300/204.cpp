#include <cstring>
#include <iostream>

using namespace std;

class Solution {
   public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        bool isPrime[n];
        memset(isPrime, true, n * sizeof(bool));

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        int res = 0;
        for (int i = 2; i < n; i++) res += isPrime[i];
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(10);
}