#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int slow = 0;
        while (nums[slow] == 0) slow++;

        int fast = slow + 1;
        while (fast < nums.size()) {
            while (fast < nums.size() && nums[fast] == 0) fast++;
            if (fast - slow - 1 < k) return false;
            slow = fast;
            fast++;
        }
        return true;
    }
};

/*
0 1 2 3
0 1 0 1

0 1 2 3 4 5 6 7
1 0 0 0 1 0 0 1
*/

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 1};
    cout << s.kLengthApart(nums, 1);
}