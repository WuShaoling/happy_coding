#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int k = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = k;  // res[i]为除当前数外左边数的乘积
            k *= nums[i];
        }

        k = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= k;  // k为当前数右边的乘积
            k *= nums[i];
        }

        return res;
    }
};
int main() {}