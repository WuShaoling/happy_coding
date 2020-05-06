#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    vector<string> permutation(string s) {
        vector<string> res;
        if (s.size() == 0) return res;

        sort(s.begin(), s.end());

        vector<bool> visited(s.size(), false);
        all(res, visited, s, "", 0);

        return res;
    }

    void all(vector<string>& res, vector<bool>& visited, string& s, string str,
             int index) {
        if (index == s.size()) {
            res.push_back(str);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (visited[i] || (i > 0 && s[i] == s[i - 1] && !visited[i - 1]))
                continue;
            visited[i] = true;
            all(res, visited, s, str + s[i], index + 1);
            visited[i] = false;
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.permutation("abca");
    for (string str : res) cout << str << endl;
}