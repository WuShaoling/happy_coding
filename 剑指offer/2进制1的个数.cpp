#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= (n - 1);
        }
    }
};

int main() {

    Solution solution;
    cout << solution.NumberOf1(10);

    return 0;
}
