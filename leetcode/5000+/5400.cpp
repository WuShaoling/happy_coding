#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> src;
        for (vector<string> path : paths) {
            src[path[0]]++;
        }
        for (vector<string> path : paths) {
            if (src.find(path[1]) == src.end()) return path[1];
        }
        return "";
    }
};

int main() {}
