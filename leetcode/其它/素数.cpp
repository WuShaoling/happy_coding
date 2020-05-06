#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> showPrimes(int n) {
        if (n <= 1) return {};
        vector<int> prime(n, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == true) {  //如果他是素数，他的所有的倍数都不是
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            cout << i << " " << prime[i] << endl;
        }
        return {};
    }
};

int main() {
    Solution s;
    s.showPrimes(100);
}