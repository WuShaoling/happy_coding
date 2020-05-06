#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    // bool isMatch(string s, string p) {
    //     int n = s.size(), m = p.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //     dp[0][0] = 1;
    //     for (int i = 2; i <= m; i += 2) {
    //         if (p[i - 1] == '*') {
    //             dp[0][i] = dp[0][i - 2];
    //         } else {
    //             break;
    //         }
    //     }

    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++) {
    //             if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             } else if (p[j - 1] == '*') {
    //                 if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
    //                     dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j -
    //                     2];
    //                 } else {
    //                     dp[i][j] = dp[i][j - 2];  // 0
    //                 }
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    bool isMatch(string s, string p) { return matchCore(s, p, 0, 0); }

    bool matchCore(const string& s, const string& p, int ps, int pp) {
        if (ps == s.size() && pp == p.size())
            return true;  //匹配到结尾了，匹配成功
        if (ps < s.size() && pp == p.size()) return false;  // p先结束，匹配失败

        // 模式的第2个是*,分两种情况：第一个能/不能匹配上
        if (pp + 1 < p.size() && p[pp + 1] == '*') {
            // 第一个匹配上了（字符相同或者和‘.’匹配），分三种情况
            // ① sIndex+1：继续用*匹配下一个
            // ② sIndex+1, pIndex+2：结束*匹配，判断下一个字符
            // ③ pIndex+2：当*前面的字符没有出现过
            // 经指正，②可以不用写，因为已经包含在①③中了，所以可以去掉中间那种情况
            if (ps < s.size() && (s[ps] == p[pp] || p[pp] == '.')) {
                return matchCore(s, p, ps + 1, pp) ||
                       matchCore(s, p, ps, pp + 2);
            } else {  // 第一个匹配不上，认为其没出现过，判断下面的
                return matchCore(s, p, ps, pp + 2);
            }
        } else {  // 模式的第二个不是*，匹配上就下一个，匹配不上就结束
            if (ps < s.size() && (s[ps] == p[pp] || p[pp] == '.')) {
                return matchCore(s, p, ps + 1, pp + 1);
            } else {
                return false;
            }
        }
    }
};

/*
public boolean matchCore(String s,int sIndex,String p,int pIndex){
    if(sIndex==s.length() && pIndex==p.length()) return
true;//匹配到结尾了，匹配成功 if(sIndex <s.length() &&  pIndex==p.length())
return false;//p先结束，匹配失败
    //模式的第2个是*,分两种情况：第一个能/不能匹配上
    if(pIndex+1<p.length() && p.charAt(pIndex+1)=='*'){
        //第一个匹配上了（字符相同或者和‘.’匹配），分三种情况
        //① sIndex+1：继续用*匹配下一个 ②
sIndex+1,pIndex+2：结束*匹配，判断下一个字符 ③pIndex+2：当*前面的字符没有出现过
        //经指正，②可以不用写，因为已经包含在①③中了，所以可以去掉中间那种情况
        if((sIndex < s.length() && p.charAt(pIndex)==s.charAt(sIndex))||(sIndex
<s.length() && p.charAt(pIndex)=='.')){
            //return matchCore(s,sIndex+1,p,pIndex) ||
matchCore(s,sIndex+1,p,pIndex+2) || matchCore(s,sIndex,p,pIndex+2); return
matchCore(s,sIndex+1,p,pIndex)  || matchCore(s,sIndex,p,pIndex+2);
        }else{//第一个匹配不上，认为其没出现过，判断下面的
            return matchCore(s,sIndex,p,pIndex+2);
        }
    }else{//模式的第二个不是*，匹配上就下一个，匹配不上就结束
         if((sIndex < s.length() && p.charAt(pIndex)==s.charAt(sIndex))||(sIndex
< s.length() && p.charAt(pIndex)=='.')){ return
matchCore(s,sIndex+1,p,pIndex+1); }else{ return false;
         }
    }
}
*/

int main() {
    Solution s;
    cout << s.isMatch("aa", "a*");
}