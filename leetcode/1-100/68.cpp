#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int i = 0;
        while (i < words.size()) {
            int len = words[i].size();
            int space = 1;
            int end = i + 1;
            for (; end < words.size(); end++) {
                if (len == maxWidth ||
                    len + space + words[end].size() > maxWidth)
                    break;
                space++;
                len += words[end].size();
            }

            string line = words[i];
            if (end - i == 1) {  // 就一个单词
                for (int a = words[i].size(); a < maxWidth; a++)
                    line.push_back(' ');
            } else if (end == words.size()) {  // 最后一行
                while (++i < end) line.append(" ").append(words[i]);
                while (line.size() < maxWidth) line.push_back(' ');
            } else {                              // 多个单词的情况
                int spaceCount = maxWidth - len;  // 计算实际需要的空格数
                int spaceGroup = end - i - 1;     // 空格分成多少组
                int spacePerGroup = spaceCount / spaceGroup;  // 每组单词数
                int leftSpace = spaceCount % spaceGroup;  // 多出来的空格

                while (++i < end) {
                    // 处理不均匀的情况
                    int n = spacePerGroup + (leftSpace > 0 ? 1 : 0);
                    leftSpace--;

                    while (n--) line.push_back(' ');
                    line.append(words[i]);
                }
            }
            ans.push_back(line);
            i = end;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"What",           "must",  "be",
                            "acknowledgment", "shall", "be"};
    vector<string> ans = s.fullJustify(words, 20);
    for (string str : ans) cout << str << endl;
}