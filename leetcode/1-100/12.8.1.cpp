#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int subtractProductAndSum(int n) {
        if (n == 0) {
            return 0;
        }
        // 123
        int arr[20] = {0};
        int len = 0;
        while (n) {
            arr[len++] = n % 10;
            n /= 10;
        }
        int res = 1;
        for (int i = 0; i < len; i++) {
            res *= arr[i];
        }
        for (int i = 0; i < len; i++) {
            res -= arr[i];
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.subtractProductAndSum(-1);
}