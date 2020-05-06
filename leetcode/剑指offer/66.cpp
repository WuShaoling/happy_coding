#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res;
        if (a.size() == 0) return res;

        int n = a.size();

        vector<int> left(n);
        left[0] = 1;
        for (int i = 1; i < n; i++) left[i] = left[i - 1] * a[i - 1];

        vector<int> right(n);
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) right[i] = right[i + 1] * a[i + 1];

        for (int i = 0; i < n; i++) {
            res.push_back(left[i] * right[i]);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> res = s.constructArr(v);
    for (int i : res) cout << i << endl;
}