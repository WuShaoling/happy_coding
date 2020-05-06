#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(),
             [](const string& str1, const string& str2) {
                 return str1 + str2 < str2 + str1;
             });

        string res = "";
        for (string str : strs) {
            res.append(str);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << s.minNumber(nums);
}