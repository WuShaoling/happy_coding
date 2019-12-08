#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = "";
        int cur = 0;
        while (1) {
            for (int i = 0; i < strs.size(); i++) {
                if (cur == strs[i].size() ||
                    (i != 0 && strs[i][cur] != strs[i - 1][cur]))
                    return res;
            }
            res += strs[0][cur];
            cur++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"abca", "abc"};
    cout << s.longestCommonPrefix(strs);
}