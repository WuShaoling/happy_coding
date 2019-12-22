#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& str, const char pattern) {
    vector<string> res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern)) {
        res.push_back(temp);
    }
    return res;
}

class Solution {
   public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        map<string, vector<string>> mm;
        for (string path : paths) {
            vector<string> ss = split(path, ' ');
            ss[0].append("/");
            for (int i = 1; i < ss.size(); i++) {
                int t = ss[i].find_first_of('(');
                string file_name = ss[i].substr(0, t);
                string content = ss[i].substr(t + 1, ss[i].size() - t - 2);
                mm[content].push_back(ss[0] + file_name);
            }
        }
        for (auto it = mm.begin(); it != mm.end(); it++) {
            if (it->second.size() > 1) res.push_back(it->second);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)",
                            "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                            "root 4.txt(efgh)"};
    vector<vector<string>> res = s.findDuplicate(paths);
    for (vector<string> v : res) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}
