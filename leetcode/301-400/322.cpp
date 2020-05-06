#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) { return 0; }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    cout << s.coinChange(coins, 11);
}
