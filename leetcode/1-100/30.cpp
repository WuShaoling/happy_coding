#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        for (int i = 0; i < words.size(); i++) visited.push_back(false);

        sort(words.begin(), words.end());
        helper(s, words, 0, "");
        return res;
    }

   private:
    void helper(string s, vector<string>& words, int index, string cur) {
        if (index == words.size()) {
            int position = 0;
            while ((position = s.find(cur, position)) != string::npos) {
                res.push_back(position);
                position++;
            }
        }

        for (int i = 0; i < words.size(); i++) {
            if (i > 0 && words[i] == words[i - 1] && !visited[i - 1]) continue;
            if (visited[i]) continue;

            visited[i] = true;
            helper(s, words, index + 1, cur + words[i]);
            visited[i] = false;
        }
    }

    vector<string> path;
    vector<bool> visited;
    vector<int> res;
};

int main() {
    Solution s;
    vector<string> words = {"foo", "bar"};
    vector<int> res = s.findSubstring("foobarfoobar", words);
    for (int i : res) cout << i << " ";
    cout << endl;
}
