#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> Permutation(string str) {
        sort(str.begin(), str.end());

        vector<bool> visited(str.size(), false);
        helper(str, 0, "", visited);
        return res;
    }

    void helper(string str, int index, string cur, vector<bool>& visited) {
        if (index >= str.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < str.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && str[i] == str[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            helper(str, index + 1, cur + str[i], visited);
            visited[i] = false;
        }
    }
    vector<string> res;
};

int main() {
    Solution s;
    vector<string> res = s.Permutation("abc");
    for (string str : res) cout << str << endl;
}