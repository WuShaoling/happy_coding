#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "0";
        if (nums.size() == 1) return to_string(nums[0]);

        vector<string> strs(nums.size());
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroCount++;
            strs[i] = to_string(nums[i]);
        }
        if (zeroCount == nums.size()) return "0";

        sort(strs.begin(), strs.end(),
             [](const string a, const string b) { return a + b > b + a; });

        string res = "";
        for (string s : strs) res.append(s);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 0};
    cout << s.largestNumber(nums);
}