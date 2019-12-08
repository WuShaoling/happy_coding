#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        int arr[100] = {0, 1, 2, 0};
        for (int i = 3; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};

int main() {}