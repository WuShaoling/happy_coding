#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> res;

        if (num.size() == 0 || words.size() == 0) return res;
        char mm[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4',
                       '5', '5', '5', '6', '6', '6', '7', '7', '7',
                       '7', '8', '8', '8', '9', '9', '9', '9'};
        for (string word : words) {
            bool find = true;
            for (int i = 0; i < word.size(); i++) {
                if (mm[word[i] - 'a'] != num[i]) {
                    find = false;
                    break;
                }
            }
            if (find) res.push_back(word);
        }
        return res;
    }
};

int main() {}