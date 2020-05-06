#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int ans = 0;
    void dfs(string &str, vector<int> &visit) {
        for (int i = 0; i < str.size(); i++) {
            if ((i > 0) && (str[i] == str[i - 1] && (visit[i - 1] == 0)))
                continue;
            if (visit[i] == 0) {
                visit[i] = 1;
                ans++;
                dfs(str, visit);
                visit[i] = 0;
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        vector<int> visit = vector<int>(tiles.size(), 0);
        sort(tiles.begin(), tiles.end());
        dfs(tiles, visit);
        return ans;
    }
};

int main() {}