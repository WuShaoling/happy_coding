#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) {
            return 0;
        }
        int l = 0, h = rotateArray.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (rotateArray[l] == rotateArray[m] && rotateArray[m] == rotateArray[h]) {
                return minInRotateArray(rotateArray, l, h);
            }
            // 0 1 2 3 4 5 6 7
            // 6 7 8 1 2 3 4 5
            // l     h
            //   m
            //     l h
            //     m
            //       lh
            if (rotateArray[m] <= rotateArray[h]) {
                h = m;
            } else {
                // 4 5 6 7 8 1 2 3
                l = m + 1;
            }
        }
        return rotateArray[l];
    }

    int minInRotateArray(vector<int> &rotateArray, int l, int h) {
        for (int i = l; i < h; i++) {
            if (rotateArray[i] > rotateArray[i + 1]) {
                return rotateArray[i + 1];
            }
        }
        return rotateArray[l];
    }

};

int main() {

    Solution solution;
    vector<int> rotateArray;
    rotateArray.push_back(4);
    rotateArray.push_back(5);
    rotateArray.push_back(6);
    rotateArray.push_back(7);
    rotateArray.push_back(8);
    rotateArray.push_back(9);
    rotateArray.push_back(1);
    rotateArray.push_back(1);
    rotateArray.push_back(1);
    rotateArray.push_back(1);

    cout << solution.minNumberInRotateArray(rotateArray);

    return 0;
}
