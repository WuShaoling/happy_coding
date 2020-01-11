#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        if (arr.size() == 0) return res;
        if (arr.size() == 1) {
            res.push_back(-1);
            return res;
        }

        map<int, int, greater<int>> mm;
        for (int i = 1; i < arr.size(); i++) mm[arr[i]]++;

        map<int, int, less<int>>::iterator it;
        for (int i = 0; i < arr.size() - 2; i++) {
            it = mm.begin();
            if (it->first == arr[i]) {
                mm[arr[i]]--;
                if (mm[arr[i]] <= 0) mm.erase(arr[i]);
            }

            it = mm.begin();
            int t = it->first;

            mm[arr[i]]--;
            if (mm[arr[i]] <= 0) mm.erase(arr[i]);

            arr[i] = t;
        }

        arr[arr.size() - 2] = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        return arr;
    }
};

int main() {
    Solution s;
    vector<int> arr = {17, 18, 5, 4, 6, 1};
    vector<int> res = s.replaceElements(arr);
    for (int i : res) cout << i << " ";
}