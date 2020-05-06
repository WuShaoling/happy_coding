#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() <= 1) return false;

        // 求个数
        map<int, int> mm;
        for (int i : deck) {
            int t = mm[i] + 1;
            mm[i] = t;
        }

        for (auto it : mm) {
            cout << it.first << " " << it.second << endl;
        }

        map<int, int>::iterator it = mm.begin();

        // 如果只有1个
        if (mm.size() == 1) return it->second > 1;

        int x = it->second;
        int gcd;
        for (++it; it != mm.end(); it++) {
            if (it->second <= 1) return false;
            x = gcd_division_iteration(x, it->second);
            if (x <= 1) return false;
        }

        return true;
    }

    int gcd_division_iteration(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};

int main() {
    Solution s;
    vector<int> deck = {1, 1, 1, 2, 2, 2, 3, 3};
    cout << s.hasGroupsSizeX(deck);
}