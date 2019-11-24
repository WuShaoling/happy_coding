#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int fib[40];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n];
    }
};

int main() {

    Solution solution;
    cout << solution.Fibonacci(10);

    return 0;
}
