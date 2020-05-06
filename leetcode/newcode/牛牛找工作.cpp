#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first < b.first) return true;
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return false;
    });

    vector<pair<int, int>> p(M);
    for (int i = 0; i < M; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    });

    vector<int> res(M);
    int idx = 0;
    int pre_max_profit = 0;
    for (int i = 0; i < p.size(); i++) {
        int max_profit = pre_max_profit;
        while (idx < v.size() && p[i].first >= v[idx].first) {
            max_profit = max(max_profit, v[idx].second);
            idx++;
        }
        res[p[i].second] = max_profit;
        pre_max_profit = max_profit;
    }

    for (int i : res) cout << i << endl;
}

// int main() {
//     int N, M;
//     cin >> N >> M;

//     vector<pair<int, int>> v(N);
//     for (int i = 0; i < N; i++) {
//         cin >> v[i].first >> v[i].second;
//     }

//     // for (pair<int, int> i : v) {
//     //     cout << i.first << " " << i.second << endl;
//     // }

//     vector<int> friends(M);
//     for (int j = 0; j < M; j++) {
//         cin >> friends[j];
//     }

//     for (int i = 0; i < friends.size(); i++) {
//         int res = 0;
//         for (int j = 0; j < N; j++) {
//             if (friends[i] >= v[j].first) {
//                 res = max(res, v[j].second);
//             }
//         }
//         cout << res << endl;
//     }

//     return 0;
// }
