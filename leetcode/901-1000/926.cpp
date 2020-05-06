#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int minFlipsMonoIncr(string S) {
        int toZero = 0;  // 翻转为0
        int toOne = 0;   // 翻转为1
        for (char c : S) {
            // 把当前位置翻转为0
            int nToZero = toZero + (c == '1');
            int nToOne = min(toOne, toZero) + (c == '0');
            toZero = nToZero;
            toOne = nToOne;
        }
        return min(toZero, toOne);
    }
};

int main() {}