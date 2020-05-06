#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mm;

        for (string str : strs) mm[getKey(str)].push_back(str);
        for (auto it : mm) res.push_back(it.second);
        return res;
    }

    string getKey(string& str) {
        int arr[26] = {0};
        for (char c : str) arr[c - 'a']++;

        string res = "";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < arr[i]; j++) {
                res += 'a' + i;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"abc", "bac", "ccabd"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (auto line : res) {
        for (auto str : line) cout << str << " ";
        cout << endl;
    }
}