#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    string arr[10] = {"",    "",    "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;

        search(digits, 0, "");
        return res;
    }

    void search(string digits, int index, string cur) {
        if (index == digits.size()) {
            res.push_back(cur);
            return;
        }

        string str = arr[digits[index] - '0'];

        for (int i = 0; i < str.size(); i++) {
            search(digits, index + 1, cur + str[i]);
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for (string s : res) {
        cout << s << endl;
    }
}