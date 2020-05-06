#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 1. 深度优先搜索
// class Solution {
//    public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         for (string str : wordDict) words[str] = true;
//         for (int i = 0; i < s.size(); i++) visited.push_back(-1);

//         return helper(s, wordDict, 0);
//     }

//     bool helper(string s, vector<string>& wordDict, int index) {
//         if (index == s.size()) return true;

//         if (visited[index] != -1) return visited[index] == 1;
//         for (int i = index + 1; i <= s.size(); i++) {
//             if (words.find(s.substr(index, i - index)) != words.end() &&
//                 helper(s, wordDict, i)) {
//                 visited[index] = 1;
//                 return true;
//             }
//         }
//         visited[index] = 0;
//         return false;
//     }

//     vector<int> visited;
//     map<string, bool> words;
// };

// 2. 广度优先搜索
// class Solution {
//    public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         map<string, bool> dict;
//         for (string str : wordDict) dict[str] = true;

//         vector<bool> visited(s.size(), false);

//         queue<int> q;
//         q.push(0);
//         while (!q.empty()) {
//             int begin = q.front();
//             q.pop();
//             if (!visited[begin]) {
//                 for (int end = begin + 1; end <= s.size(); end++) {
//                     string subStr = s.substr(begin, end - begin);
//                     if (dict.find(subStr) != dict.end()) {
//                         q.push(end);
//                         if (end == s.size()) return true;
//                     }
//                 }
//                 visited[begin] = true;
//             }
//         }
//         return false;
//     }
// };

// 3. 动态规划
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> dict;
        for (string str : wordDict) dict[str] = true;
        //         i
        // 0 1 2 3 4 5 6
        // T F F T
        // d o g c a t
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
            return dp[s.size()];
        }
    }
};

//    public
//     boolean wordBreak(String s, List<String> wordDict) {
//         Set<String> wordDictSet = new HashSet(wordDict);
//         boolean[] dp = new boolean[s.length() + 1];
//         dp[0] = true;
//         for (int i = 1; i <= s.length(); i++) {
//             for (int j = 0; j < i; j++) {
//                 if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[s.length()];
//     }

int main() {
    Solution s;
    vector<string> wordDict = {"a",         "aa",        "aaa",     "aaaa",
                               "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                               "aaaaaaaaa", "aaaaaaaaaa"};
    string ss =
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaa"
        "aaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaa"
        "aaaa"
        "aab";
    cout << s.wordBreak(ss, wordDict);
}
