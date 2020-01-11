#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        dfs(amount, coins, 0);
        return res;
    }

   private:
    void dfs(int amount, vector<int>& coins, int index) {
        if (amount == 0) {
            res++;
            return;
        }

        for (int i = index; i < coins.size(); i++) {
            if (coins[i] > amount) return;
            dfs(amount - coins[i], coins, i);
        }
    }

    int res = 0;
};

int main() {
    Solution s;
    vector<int> coins = {10};
    cout << s.change(10, coins);
}