#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> mm;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            mm[t].push_back(str);
        }
        for (auto i = mm.begin(); i != mm.end(); i++) {
            res.push_back(i->second);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (vector<string> v : res) {
        for (string vv : v) {
            cout << vv << " ";
        }
        cout << endl;
    }
}