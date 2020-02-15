#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for (int i = 1; i <= n / 2; i++) {
            if (noZero(i) && noZero(n - i)) {
                res.push_back(i);
                res.push_back(n - i);
                return res;
            }
        }
        return res;
    }

    bool noZero(int n) {
        if (n == 0) return false;
        while (n) {
            if (n % 10 == 0) return false;
            n /= 10;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> res = s.getNoZeroIntegers(1010);
    for (int i : res) cout << i << " ";
}