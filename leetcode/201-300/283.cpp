#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        while (j < nums.size() && nums[j] != 0) j++;

        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {};
    s.moveZeroes(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}