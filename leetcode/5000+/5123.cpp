#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CombinationIterator {
   public:
    CombinationIterator(string characters, int combinationLength) {
        dfs(characters, combinationLength, 0, "");
        reverse(paths.begin(), paths.end());
    }

    void dfs(string str, int len, int index, string path) {
        if (path.size() == len) {
            paths.push_back(path);
            return;
        }

        for (int i = index; i < str.size(); i++) {
            dfs(str, len, i + 1, path + str[i]);
        }
    }

    string next() {
        string str = paths[paths.size() - 1];
        paths.pop_back();
        return str;
    }

    bool hasNext() { return paths.size() > 0; }

   private:
    vector<string> paths;
};

int main() { CombinationIterator s("abc", 2); }