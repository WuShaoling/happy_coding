#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        vector<string> strs = split(s);
        if (strs.size() == 0) return "";

        ostringstream output;
        output << strs[strs.size() - 1];
        for (int i = strs.size() - 2; i >= 0; i--) {
            output << " " << strs[i];
        }
        return output.str();
    }

    vector<string> split(string str) {
        stringstream input(str);
        string temp;
        vector<string> ans;
        while (getline(input, temp, ' ')) {
            if (temp.size() == 0) continue;

            int spaces = 0;
            for (char c : temp)
                if (c == ' ') spaces++;
            if (spaces == temp.size()) continue;

            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {}