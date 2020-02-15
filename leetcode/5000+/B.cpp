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
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> res;
        long long doubleX = tomatoSlices - 2 * cheeseSlices;
        if (doubleX >= 0 && doubleX % 2 == 0) {
            long long x = doubleX / 2;
            long long y = cheeseSlices - x;
            if (x >= 0 && y >= 0) {
                res.push_back(x);
                res.push_back(y);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    solution.numOfBurgers(2385088, 164763);
}