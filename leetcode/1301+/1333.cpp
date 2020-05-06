#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool compare(const vector<int>& s1, const vector<int>& s2) {
    if (s1[1] == s2[1]) return s1[0] > s2[0];
    return s1[1] > s2[1];
}

class Solution {
   public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                  int veganFriendly, int maxPrice,
                                  int maxDistance) {
        vector<vector<int>> temp;
        for (vector<int> r : restaurants) {
            bool flag = veganFriendly == 1 ? r[2] == 1 : true;
            if (flag && r[3] <= maxPrice && r[4] <= maxDistance) {
                temp.push_back(r);
            }
        }
        sort(temp.begin(), temp.end(), compare);
        for (vector<int> v : temp) {
            for (int i : v) {
                cout << i << " ";
            }
            cout << endl;
        }

        vector<int> res;
        for (vector<int> t : temp) res.push_back(t[0]);

        return res;
    }
};

int main() {
}