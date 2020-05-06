#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i : nums) {
            i = abs(i) - 1;
            if (nums[i] > 0) nums[i] *= -1;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};

int main() {}
