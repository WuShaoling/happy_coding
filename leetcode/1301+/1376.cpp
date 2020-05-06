#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
   public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        // 求领导的下属
        vector<vector<int>> mana(manager.size(), vector<int>());
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) continue;
            mana[manager[i]].push_back(i);
        }

        int res = 0;
        dfs(mana, informTime, headID, 0, res);
        return res;
    }

   private:
    void dfs(vector<vector<int>>& mana, vector<int>& informTime, int id,
             int time, int& res) {
        if (mana[id].empty()) {
            res = max(res, time);
            return;
        }
        time += informTime[id];
        for (auto next : mana[id]) {
            dfs(mana, informTime, next, time, res);
        }
    }
};

int main() {}
