#include <iostream>
#include <vector>
using namespace std;

class CustomFunction {
   public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};

class Solution {
   public:
    vector<vector<int> > findSolution(CustomFunction& customfunction, int z) {
        int left = 1;
        int right = 1000;
        vector<vector<int> > res;
        for (; left <= 1000, right >= 1;) {
            int tmp = customfunction.f(left, right);
            if (tmp == z) {
                // vector<int> t = {left, right};
                res.push_back({left, right});
                left++;
            } else if (tmp > z) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};

int main() {}