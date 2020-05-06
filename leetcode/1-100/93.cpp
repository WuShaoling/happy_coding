#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 || s.size() < 4) return {};
        return backtrack(s, 0);
    }

   private:
    vector<string> backtrack(string s, int n) {
        // 如果字符串用完了 或者 剩下的 字符串长度 不够拆分为 还需的数字个数
        if (s == "" || s.size() < 4 - n) return {};

        // 最后一个数字了
        if (n == 3) {
            // 如果子串以 0 开头且这个子串不是 "0"，不符合，剪枝
            if (s[0] == '0' && s != "0") return {};
            if (stoi(s) <= 255) return {s};
            return {};
        }

        vector<string> ans;
        for (int i = 1; i <= 3 && i < s.size(); i++) {
            string curStr = s.substr(0, i);

            // 如果子串以 0 开头且这个子串不是 "0"，不符合，剪枝
            if (curStr[0] == '0' && curStr != "0") continue;

            // 根据数字范围进行剪枝
            if (stoi(curStr) > 255) continue;

            vector<string> subAns = backtrack(s.substr(i, s.size() - i), n + 1);

            for (string str : subAns) {
                ans.push_back(curStr + "." + str);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.restoreIpAddresses("010010");
    for (string ip : ans) cout << ip << endl;
}