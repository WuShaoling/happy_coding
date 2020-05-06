#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        vector<bool> visited(S.size(), false);
        helper(S, "", 0, visited);
        return res;
    }

    void helper(string& S, string cur, int index, vector<bool>& visited) {
        if (index == S.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < S.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && S[i] == S[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            helper(S, cur + S[i], index + 1, visited);
            visited[i] = false;
        }
    }

    vector<string> res;
};

int main() {
    Solution s;
    vector<string> res = s.permutation("qqe");
    for (string str : res) cout << str << endl;
}