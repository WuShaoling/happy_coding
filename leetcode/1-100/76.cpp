#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        if (!preCheck(s, t)) return "";

        unordered_map<char, int> t_map;
        for (char c : t) t_map[c]++;
        int totalDiffChar = t_map.size();

        int begin = 0;
        int len = s.size();

        int i = 0;
        int count = 0;
        unordered_map<char, int> s_map;
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];

            s_map[c]++;
            if (s_map[c] == t_map[c]) count++;

            // 当前 [i, j] 能覆盖 t 中的所有字符
            if (count == totalDiffChar) {
                // 尝试右移 i
                for (; i <= j; i++) {
                    if (len > j - i + 1) {
                        begin = i;
                        len = j - i + 1;
                        if (len == t.size()) return s.substr(begin, len);
                    }
                    if (s_map[s[i]] > t_map[s[i]])
                        s_map[s[i]]--;
                    else
                        break;
                }
            }
        }

        return s.substr(begin, len);
    }

    bool preCheck(string& s, string& t) {
        int arrS[128] = {0};
        int arrT[128] = {0};
        for (char c : s) arrS[c]++;
        for (char c : t) arrT[c]++;
        for (int i = 0; i < 128; i++) {
            if (arrS[i] < arrT[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.minWindow("a", "aa");
}