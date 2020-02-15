#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> fraction(vector<int>& cont) {
        if (cont.size() == 1) {
            vector<int> res = {cont[0], 1};
            return res;
        }
        int t1 = 1;
        int t2 = cont[cont.size() - 1];
        for (int i = cont.size() - 2; i >= 0; i--) {
            int t = t2;
            t2 = cont[i] * t2 + t1;
            t1 = t;
        }
        vector<int> res = {t2, t1};
        return res;
    }
};

int main() {
    Solution s;
    // vector<int> cont = {3, 2, 0, 2};
    vector<int> cont = {0, 0, 3};
    vector<int> res = s.fraction(cont);
    cout << res[0] << " " << res[1] << endl;
}