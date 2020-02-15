#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countPrimes(int n) {
        if (n <= 1) return 0;

        vector<bool> isPrime(n, false);
        for (int i = 2; i * i < n; i += 2) {
            if (isPrime[i]) {
                isPrime[i] = false;
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == true) res++;
        }

        return res;
    }
};

int main() {}