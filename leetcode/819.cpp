#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        for (int i = 0; i < paragraph.length(); i++) {
            if (!isalpha(paragraph[i])) {
                paragraph[i] = ' ';
            } else {
                paragraph[i] = tolower(paragraph[i]);
            }
        }
        map<string, int> mm;
        stringstream input(paragraph);
        string t;
        while (input >> t)
            mm[t]++;
        for (int i = 0; i < banned.size(); i++) {
            mm[banned[i]] = 0;
        }
        int max = -1;
        map<string, int>::iterator it = mm.begin();
        while (it != mm.end()) {
            if (it->second > max) {
                max = it->second;
                t = it->first;
            }
            it++;
        }
        return t;
    }
};

int main() {
    Solution solution;
    vector<string> v;
    v.push_back("world");

    cout << solution.mostCommonWord("hello world world", v);
}
