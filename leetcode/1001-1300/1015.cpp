#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int ans = 0;
        int t = 0;
        while (t % K != 0) {
            t = t % K;
            t = t * 10 + 1;
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.smallestRepunitDivByK(3);
}