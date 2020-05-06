#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size();) {
            string line = to_string(nums[i]);

            int j = i + 1;
            for (; j < nums.size(); j++) {
                long a = nums[j];
                long b = nums[j - 1];
                if (a - b != 1) break;
            }

            if (j != i + 1) line += "->" + to_string(nums[j - 1]);
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2147483648, -2147483647, 2147483647};
    s.summaryRanges(nums);
}