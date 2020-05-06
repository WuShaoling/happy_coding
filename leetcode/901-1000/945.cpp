#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minIncrementForUnique(vector<int>& A) {
        int res = 0;
        vector<int> v(40000, 0);
        int m = 0;
        for (int a : A) {
            v[a]++;
            m = max(m, a);
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            if (v[i] > 1) {
                res += v[i] - 1;
                v[i + 1] += v[i] - 1;
            }
        }
        if (v[m] > 1) {
            int d = v[m] - 1;
            res += (d + 1) * d / 2;
        }

        return res;
    }
    // int minIncrementForUnique(vector<int>& A) {
    //     sort(A.begin(), A.end());
    //     int res = 0;
    //     for (int i = 1; i < A.size(); i++) {
    //         if (A[i] <= A[i - 1]) res += A[i - 1] + 1;
    //     }
    //     return res;
    // }

    // int minIncrementForUnique(vector<int>& A) {
    //     int res = 0;
    //     vector<int> arr(80005, -1);
    //     for (int i : A) {
    //         res += findPos(i, arr) - i;
    //     }
    //     return res;
    // }

    // int findPos(int a, vector<int>& pos) {
    //     int b = pos[a];
    //     // 如果a对应的位置pos[a]是空位，直接放入即可。
    //     if (b == -1) {
    //         pos[a] = a;
    //         return a;
    //     }
    //     // 否则向后寻址
    //     //
    //     因为pos[a]中标记了上次寻址得到的空位，因此从pos[a]+1开始寻址就行了（不需要从a+1开始）。
    //     b = findPos(b + 1, pos);
    //     pos[a] =
    //         b;  //
    //         寻址后的新空位要重新赋值给pos[a]哦，路径压缩就是体现在这里。
    //     return b;
    // }
};

int main() {}