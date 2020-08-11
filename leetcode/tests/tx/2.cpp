#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> set1(n);
    for (int i = 0; i < n; i++) cin >> set1[i].first >> set1[i].second;

    vector<pair<int, int>> set2(n);
    for (int i = 0; i < n; i++) cin >> set2[i].first >> set2[i].second;

    sort(set1.begin(), set1.begin(),
         [](pair<int, int>& p1, pair<int, int>& p2) {
             if (p1.first == p2.first) return p1.second < p2.second;
             return p1.first < p2.first;
         });

    long ans = 0;
    for (int i = 0; i < n; i++) {  // 无序集
        pair<int, int> p = set2[i];
        long minDis = (set1[1].first - p.first) * (set1[1].first - p.first) +
                      (set1[1].second - p.second) * (set1[1].second - p.second);
        for (int j = 1; j < n; j++) {  // 有序集
            long dis =
                (set1[j].first - p.first) * (set1[j].first - p.first) +
                (set1[j].second - p.second) * (set1[j].second - p.second);
            if (dis < minDis) {
                minDis = dis;
            } else {
                break;
            }
            ans = min(ans, minDis);
        }
    }

    printf("%.3lf\n", sqrt(ans));
}