#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (int i = 0; i < queries.size(); i++) {
            res.push_back(match(queries[i], pattern));
        }
        return res;
    }

    bool match(string word, string pattern) {
        int w1 = 0;
        int p1 = 0;

        while (w1 != word.size() && p1 != pattern.size()) {
            if (word[w1] == pattern[p1]) {
                w1++, p1++;
            } else if (isupper(word[w1])) {
                return false;
            } else {
                w1++;
            }
        }
        if (p1 != pattern.size()) {
            return false;
        }
        for (int i = w1; i < word.size(); i++) {
            if (isupper(word[i])) return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
                              "ForceFeedBack"};
    vector<bool> res = s.camelMatch(queries, "FoBaT");
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}