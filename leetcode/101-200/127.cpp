#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (wordList.size() == 0) return false;

        bool has = false;
        for (string word : wordList) {
            if (word == endWord) {
                has = true;
                break;
            }
        }
        if (!has) return false;

        vector<bool> visited(wordList.size(), false);
        helper(beginWord, endWord, wordList, visited, 0);

        return res == INT_MAX ? 0 : res;
    }

   private:
    int helper(string& cur, string& target, vector<string>& wordList,
               vector<bool>& visited, int len) {
        if (cur == target) {
            return len + 1;
        }

        for (int i = 0; i < wordList.size(); i++) {
            if (visited[i] || !match(cur, wordList[i])) continue;

            string key = wordList[i] + "_" + target;
            if (mm.find(key) != mm.end()) return len + mm[key];

            visited[i] = true;
            int count = helper(wordList[i], target, wordList, visited, len + 1);
            if (count != -1) {
                mm[key] = count;
                res = min(res, len + count);
            }
            visited[i] = false;
        }

        return -1;
    }

    bool match(string& cur, string& target) {
        int diff = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] != target[i]) diff++;
            if (diff > 1) return false;
        }
        return true;
    }

    int res = INT_MAX;
    map<string, int> mm;
};

int main() {
    Solution s;
    vector<string> v = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength("hit", "cog", v);
}