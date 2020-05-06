#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int n = height.size();

        vector<pair<int, int>> people;
        for (int i = 0; i < n; i++) people.push_back({height[i], weight[i]});

        sort(people.begin(), people.end(),
             [](pair<int, int>& p1, pair<int, int>& p2) {
                 if (p1.first == p2.first) return p1.second > p2.second;
                 return p1.first < p2.first;
             });
        return getMax(people);
    }

    int getMax(vector<pair<int, int>>& people) {
        int n = people.size();
        vector<pair<int, int>> tails(n);
        int res = 0;
        for (pair<int, int> p : people) {
            // 寻找第一个大于 num 的数，求下界
            int left = 0, right = res, mid;
            while (left < right) {
                mid = left + ((right - left) >> 1);
                if (tails[mid].first < p.first &&
                    tails[mid].second < p.second) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            tails[left] = p;
            if (right == res) res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> height = {5401, 9628, 3367, 6600, 6983,
                          7853, 5715, 2654, 4453, 8619};
    vector<int> weight = {3614, 1553, 2731, 7894, 8689,
                          182,  7632, 4465, 8932, 4304};
    cout << s.bestSeqAtIndex(height, weight);
}