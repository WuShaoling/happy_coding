#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 2) {
            return number;
        }
        int a = 1;
        int b = 2;
        int res = 0;
        for (int i = 2; i < number; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;

    }
};

int main() {

    Solution solution;
    cout << solution.jumpFloor(10);

    return 0;
}
