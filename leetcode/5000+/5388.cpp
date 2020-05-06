#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string reformat(string s) {
        int nums = 0;
        string s_num;
        string s_char;
        for (char c : s) {
            if (isdigit(c)) {
                s_num.push_back(c);
            } else {
                s_char.push_back(c);
            }
        }

        if (s_num.size() == s_char.size() ||
            s_num.size() - s_char.size() == 1 ||
            s_num.size() - s_char.size() == -1) {
            // 从s_num开始拼接
            if (s_num.size() < s_char.size()) {
                swap(s_num, s_char);
            }
            string ans;
            for (int i = s_num.size() - 1, j = s_char.size() - 1; j >= 0;
                 i--, j--) {
                ans.push_back(s_num[i]);
                ans.push_back(s_char[j]);
            }
            if (s_num.size() != s_char.size()) {
                ans.push_back(s_num[0]);
            }

            return ans;
        }

        return "";
    }
};

int main() {
    Solution s;
    cout << s.reformat("a0b1c");
}