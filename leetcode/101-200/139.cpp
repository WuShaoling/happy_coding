#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string str : wordDict) words[str] = true;
        for (int i = 0; i < s.size(); i++) visited.push_back(-1);

        return helper(s, wordDict, 0);
    }

    bool helper(string s, vector<string>& wordDict, int index) {
        if (index == s.size()) return true;

        if (visited[index] != -1) return visited[index] == 1;

        for (int i = index + 1; i <= s.size(); i++) {
            if (words.find(s.substr(index, i - index)) != words.end() &&
                helper(s, wordDict, i)) {
                visited[index] = 1;
                return true;
            }
        }
        visited[index] = 0;
        return false;
    }

    vector<int> visited;
    map<string, bool> words;
};

// public class Solution {
//     public boolean wordBreak(String s, List<String> wordDict) {
//         return word_Break(s, new HashSet(wordDict), 0, new
//         Boolean[s.length()]);
//     }
//     public boolean word_Break(String s, Set<String> wordDict, int start,
//     Boolean[] memo) {
//         if (start == s.length()) {
//             return true;
//         }
//         if (memo[start] != null) {
//             return memo[start];
//         }
//         for (int end = start + 1; end <= s.length(); end++) {
//             if (wordDict.contains(s.substring(start, end)) && word_Break(s,
//             wordDict, end, memo)) {
//                 return memo[start] = true;
//             }
//         }
//         return memo[start] = false;
//     }
// }

string ss =
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    "aab";
int main() {
    Solution s;
    vector<string> wordDict = {"a",         "aa",        "aaa",     "aaaa",
                               "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                               "aaaaaaaaa", "aaaaaaaaaa"};
    cout << s.wordBreak(ss, wordDict);
}
