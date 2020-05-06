#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        map<string, vector<string>> mm;
        for (string str : wordList) {
            for (int i = 0; i < str.size(); i++) {
                string key = str.substr(0, i).append("*").append(
                    str.substr(i + 1, str.size() - i - 1));
                mm[key].push_back(str);
            }
        }

        map<string, bool> visited;

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        visited[beginWord] = true;

        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();

            string word = p.first;
            int level = p.second;
            visited[word] = true;

            for (int i = 0; i < word.size(); i++) {
                string key = word.substr(0, i).append("*").append(
                    word.substr(i + 1, word.size() - i - 1));
                for (string adjacentWord : mm[key]) {
                    if (adjacentWord == endWord) return level + 1;
                    if (!visited[adjacentWord]) {
                        q.push(make_pair(adjacentWord, level + 1));
                        visited[adjacentWord] = true;
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<string> v = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength("hit", "cog", v);
}