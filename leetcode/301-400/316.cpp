#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;

        // 字符到索引的映射
        map<char, vector<int>> mm;
        for (int i = 0; i < s.size(); i++) mm[s[i]].push_back(i);

        int min_idx = -1;
        int count = mm.size();
        string ans;
        while (ans.size() != count) {
            // 每次选择一个没有添加的字符，判断插入这个字母以后，在这个位置后面，剩下的单词都能出现
            for (auto& it : mm) {
                bool ok = false;

                // 找第一个大于 min_idx 的数
                int i =
                    lower_bound(it.second.begin(), it.second.end(), min_idx) -
                    it.second.begin();

                if (i < it.second.size() &&
                    checkRemainChars(mm, it.first, it.second[i])) {
                    ans.push_back(it.first);
                    min_idx = it.second[i];
                    mm.erase(it.first);
                    ok = true;
                    break;
                }

                if (ok) break;  // 再次从map头扫描
            }
        }

        return ans;
    }

   private:
    // 查找其他字符能否放在其后
    bool checkRemainChars(map<char, vector<int>>& mm, char c, int target) {
        for (auto& it : mm) {
            if (it.first == c) continue;
            // 如果最大值小于target，直接返回false
            if (it.second.back() < target) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.removeDuplicateLetters("cbacdcbc");
}