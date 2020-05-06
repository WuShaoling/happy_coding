#include <vector>
#include <iostream>

using namespace std;

class Solution {
   public:
    vector<int> printNumbers(int n) {
        int _max = 9;
        for (int i = 1; i < n; i++) _max = _max * 10 + 9;

        vector<int> res(_max);
        for (int i = 1; i <= _max; i++) res[i - 1] = i;
        return res;
    }
};

int main() {
    Solution s;
    s.printNumbers(0);
}