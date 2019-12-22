/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

#include <ctype.h>
#include <iostream>
#include <string>

// @lc code=start
class Solution {
   public:
    string decodeString(string s) { 
        return decode(0, s); 
    }

    string decode(string s, int i) {
        string res = "";

        for (; i < s.size(); i++;) {
            if (isdigit(s[i])) {
                string t = "";
                int n = s[i] - '0';
                for (++i; i < s.size(); i++) {
                    if (s[i] == ']') {
                        while (n--) t += t;
                        res += t;
                        break;
                    } else if (isdigit(s[i])) {
                        t += s[i];
                    } else {
                        t += s[i];
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end
