#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char pattern) {
    vector<string> res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern)) {
        if (temp.size() != 0) res.push_back(temp);
    }
    return res;
}

class Solution {
   public:
    string ReverseSentence(string str) {
        vector<string> words = split(str, ' ');
        if (words.size() <= 1) return str;

        int j = 0;
        string res;
        for (int i = words.size() - 1; i >= 0; i--) {
            while (j < str.size() && str[j] == ' ') {
                res.append(" ");
                j++;
            }
            res.append(words[i]);
            while (j < str.size() && str[j] != ' ') j++;
        }
        while (j < str.size() && str[j] == ' ') {
            res.append(" ");
            j++;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << "-" << s.ReverseSentence("stu am i") << "-";
}