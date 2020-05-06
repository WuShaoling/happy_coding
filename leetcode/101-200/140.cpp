#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> dict;
        for (string str : wordDict) dict[str] = true;

        cout << judge(s, dict) << endl;

        map<int, vector<string>> memo;
        return dfs(s, dict, 0, memo);
    }

    bool judge(string& s, map<string, bool>& dict) {
        vector<int> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string subStr = s.substr(j, i - j);
                if (dp[j] && dict.find(subStr) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

    vector<string> dfs(string& s, map<string, bool>& dict, int index,
                       map<int, vector<string>>& memo) {
        if (memo.count(index)) return memo[index];

        vector<string> res;
        for (int i = index; i < s.size(); i++) {
            string cur = s.substr(index, i - index + 1);
            if (dict.find(cur) != dict.end()) {
                if (i == s.size() - 1) res.push_back(cur);
                vector<string> tmp = dfs(s, dict, i + 1, memo);
                for (string str : tmp) res.push_back(cur + " " + str);
            }
        }
        memo[index] = res;
        return res;
    }
};

// vector<string> dfs(string s, set<string> &wordDict, int index,
//                    map<int, vector<string>> &memo) {
//     if (memo.count(index)) return memo[index];
//     vector<string> ret;
//     for (int i = index; i < s.size(); i++) {
//         string cur = s.substr(index, i - index + 1);
//         if (wordDict.count(cur)) {
//             if (i == s.size() - 1) ret.push_back(cur);
//             vector<string> tmp = dfs(s, wordDict, i + 1, memo);
//             for (string e : tmp) ret.push_back(cur + " " + e);
//         }
//     }
//     memo[index] = ret;
//     return ret;
// }

int main() {
    Solution s;
    vector<string> word = {"cat", "cats", "and", "sand", "dog"};
    s.wordBreak("catsanddog", word);
}