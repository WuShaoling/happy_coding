#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> strs(17);
        for (string word : words) strs[word.size()].push_back(word);

        for (int i = 1; i <= 16; i++) dfs(strs, "", i, 0);
        return ans;
    }

   private:
    void dfs(vector<vector<string>>& strs, string preWrod, int idx, int len) {
        if (idx >= 17 || strs[idx].empty() || len + 17 - idx <= ans) {
            return;
        }

        for (string word : strs[idx]) {
            if (preWrod == "" || match(preWrod, word)) {
                ans = max(ans, len + 1);
                dfs(strs, word, idx + 1, len + 1);
            }
        }
    }

    bool match(string preWrod, string word) {
        int diff = 0;
        for (int i = 0, j = 0; i < preWrod.size() && j < word.size();) {
            if (preWrod[i] == word[j]) {
                i++, j++;
            } else {
                diff++;
                if (diff == 2) return false;
                j++;
            }
        }
        return true;
    }

    int ans = 0;
};

int main() {
    Solution s;
    vector<string> words = {"sgtnz",    "sgtz",      "sgz",     "ikrcyoglz",
                            "ajelpkpx", "ajelpkpxm", "srqgtnz", "srqgotnz",
                            "srgtnz",   "ijkrcyoglz"};
    cout << s.longestStrChain(words);
}