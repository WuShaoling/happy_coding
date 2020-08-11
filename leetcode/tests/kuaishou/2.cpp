#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 返回无重复幂因子的 N进制完美数之和的所有幂因子
     * @param R int整型
     * @param N int整型 N进制
     * @return int整型vector
     */
    vector<int> GetPowerFactor(int R, int N) {
        // 求 N 进制
        vector<int> mods;
        int t;
        while (R) {
            t = R % N;  // 取余

            // 余数大于1的直接返回，不符合
            if (t > 1) return {};

            mods.push_back(t);
            R /= N;
        }

        // 排除掉余数为0的
        vector<int> res;
        for (int i = 0; i < mods.size(); i++) {
            if (mods[i] == 1) res.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    s.GetPowerFactor(100, 3);
}

/*

39/3 = 13 ... 0
13/3 = 4  ... 1
4/3  = 1  ... 1
1/3  = 0  ... 1

33/3 = 11 ... 0
11/3 = 3  ... 2
3/3  = 1  ... 0

1/3 = 0 ... 1

321
311

1*3^1 + 1*3*1 + 1*3^3 = 1 + 3 + 9
*/