#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int cur = 0;
        int two = nums.size() - 1;

        while (cur <= two) {
            if (nums[cur] == 0) {  // 如果当前位置等于0，与 zero 位置交换
                swap(nums[cur], nums[zero]);
                cur++;
                zero++;
            } else if (nums[cur] == 1) {  // 当前位置为1，无需交换，继续向后找
                cur++;
            } else {
                swap(nums[cur], nums[two]);  // 当前位置为2，与 two 所在位置交换
                two--;
            }
        }
    }
};

int main() {}