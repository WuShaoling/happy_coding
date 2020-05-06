#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string decodeString(string s) {
        stack<string> str_stack;
        stack<int> num_stack;
        for (int i = 0; i < s.size();) {
            // cout << s[i] << " ";
            if (isdigit(s[i])) {
                // 向右找到第一个非数字字符
                int j = i + 1;
                while (j < s.size() && isdigit(s[j])) j++;
                // 将数字入栈
                num_stack.push(stoi(s.substr(i, j - i)));
                i = j;
            } else if (s[i] == '[') {
                // 向右找连续的字母
                int j = i + 1;
                while (j < s.size() && isalpha(s[j])) j++;
                // 把连续的子串入栈
                str_stack.push(s.substr(i + 1, j - i - 1));
                i = j;
            } else if (s[i] == ']') {
                // 出栈
                string repeat = repeatStr(str_stack.top(), num_stack.top());
                str_stack.pop();
                num_stack.pop();
                // 如果栈非空，还需要合并操作
                if (!str_stack.empty()) {
                    repeat = str_stack.top() + repeat;
                    str_stack.pop();
                }
                str_stack.push(repeat);
                i++;
            } else {
                int j = i + 1;
                while (j < s.size() && isdigit(s[j])) j++;
                string subStr = s.substr(i, j - i);
                // 如果栈非空，还需要合并操作
                if (!str_stack.empty()) {
                    subStr = str_stack.top() + subStr;
                    str_stack.pop();
                }
                str_stack.push(subStr);
                i = j;
            }
        }
        string ans = "";
        while (!str_stack.empty()) {
            ans = str_stack.top() + ans;
            str_stack.pop();
        }
        return ans;
    }

    string repeatStr(string str, int count) {
        string ans;
        for (int i = 0; i < count; i++) {
            ans.append(str);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.decodeString("3[a]2[b4[F]c]") << endl;
    //     2
    // aaa bFFFF
    // abbbabbbabbbcc
    // 3[abbb]
    // abbbabbbabbbcc
}

// 3[aa3[b]]2[bc]
// 3[aabbb]2
// 32 2
// aaabcdabcdabcd bc