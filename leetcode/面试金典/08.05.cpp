#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int multiply(int A, int B) {
        if (B == 0) return 0;
        if (B == 1) return A;

        if (B & 1) {
            return multiply(A << 1, B >> 1) + A;
        }
        return multiply(A << 1, B >> 1);
    }
};

// class Solution {
//    public:
//     int multiply(int A, int B) {
//         if (A == 0 || B == 0) return 0;

//         // 保证 abs(A) >= abs(B)，从而实现最小的递归次数
//         if (abs(A) < abs(B)) {
//             swap(A, B);
//         }
//         // 保证 B 是正数
//         if (B < 0) {
//             B *= -1;
//             A *= -1;
//         }

//         return doMultiply(A, B);
//     }

//     int doMultiply(int A, int B) {
//         if (B == 1) return A;
//         if (B == 0) return 0;
//         int t = doMultiply(A, B >> 1);
//         t <<= 1;
//         if ((B & 1) == 1) t += A;
//         return t;
//     }
// };

int main() {
    Solution s;
    cout << s.multiply(2, -10);
}