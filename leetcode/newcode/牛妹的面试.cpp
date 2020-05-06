#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int mountainSequence(vector<int>& numberList) {
        int n = numberList.size();

        vector<int> dpLeft(n + 1, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (numberList[j] < numberList[i])
                    dpLeft[i] = max(dpLeft[i], dpLeft[j] + 1);
            }
        }

        vector<int> dpRight(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (numberList[i] > numberList[j])
                    dpRight[i] = max(dpRight[i], dpRight[j] + 1);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dpLeft[i] + dpRight[i] - 1);
        }
        return res;
    }

    /**
     * 返回最大山峰序列长度
     * @param numberList int整型vector 给定的序列
     * @return int整型
     */
    // int mountainSequence(vector<int>& numberList) {
    //     int n = numberList.size();

    //     vector<int> dpLeft(n + 1, 1);
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (numberList[j] < numberList[i])
    //                 dpLeft[i] = max(dpLeft[i], dpLeft[j] + 1);
    //         }
    //     }

    //     vector<int> dpRight(n + 1, 1);
    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int j = n - 1; j > i; j--) {
    //             if (numberList[i] > numberList[j])
    //                 dpRight[i] = max(dpRight[i], dpRight[j] + 1);
    //         }
    //     }

    //     int res = 0;
    //     for (int i = 0; i < n; i++) {
    //         res = max(res, dpLeft[i] + dpRight[i] - 1);
    //     }
    //     return res;
    // }
};

int main() {}