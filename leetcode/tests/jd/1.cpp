#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

bool solve(vector<pair<int, int>>& A) {
    int n = A.size();
    // 保证有序
    for (int i = 0; i < n; i++) {
        if (A[i].first > A[i].second) {
            swap(A[i].first, A[i].second);
        }
    }
    sort(A.begin(), A.end());
    for (auto it : A) {
        cout << it.first << " " << it.second << endl;
    }

    if (A[0].first != A[1].first || A[0].second != A[1].second) return false;
    if (A[2].first != A[3].first || A[2].second != A[3].second) return false;
    if (A[4].first != A[5].first || A[4].second != A[5].second) return false;

    if (A[0].first == A[2].first) {
        if ((A[0].second == A[4].first && A[2].second == A[4].second) ||
            (A[0].second == A[4].second && A[2].second == A[4].first)) {
            return true;
        }
    }
    return false;
}

// bool solve(vector<pair<int, int>>& A) {
//     int n = A.size();
//     // 保证有序
//     for (int i = 0; i < n; i++) {
//         if (A[i].first > A[i].second) {
//             swap(A[i].first, A[i].second);
//         }
//     }

//     // 统计边的数量
//     map<pair<int, int>, int> mm;
//     for (pair<int, int> p : A) {
//         mm[p]++;
//     }

//     if (mm.size() > 3) return false;
//     if (mm.size() == 1) {  //正方体
//         auto it = mm.begin();
//         return it->second == 6 && it->first.first == it->first.second;
//     }
//     if (mm.size() == 2) {
//         auto first = mm.begin();
//         auto second = mm.begin();
//         ++second;
//         if (first->second == 4 && second->second == 2) {
//             int a1 = first->first.first;
//             int a2 = first->first.second;
//             int b1 = second->first.first;
//             int b2 = second->first.second;
//             if (b1 == b2 && (b1 == a1 || b1 == a2)) return true;
//             return false;
//         } else if (first->second == 2 && second->second == 4) {
//             int a1 = first->first.first;
//             int a2 = first->first.second;
//             int b1 = second->first.first;
//             int b2 = second->first.second;
//             if (a1 == a2 && (a1 == b1 || a1 == b2)) return true;
//             return false;
//         } else {
//             return false;
//         }
//     }
//     if (mm.size() == 3) {
//         for (auto it : mm) {
//             if (it.second != 2) return false;  // 每种类型的边出现2次
//             if (it.first.first == it.first.second) return false;  // 不能相等
//         }
//         // 统计点出现的次数
//         map<int, int> m2;
//         for (auto it : mm) {
//             m2[it.first.first]++;
//             m2[it.first.second]++;
//         }
//         // 必须3个点
//         if (m2.size() != 3) return false;
//         // 每个点数量必须是2
//         for (auto it : m2) {
//             if (it.second != 2) return false;
//         }
//         return true;
//     }

//     return true;
// }

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<pair<int, int>> A(6);
        for (int i = 0; i < 6; ++i) cin >> A[i].first >> A[i].second;
        cout << (solve(A) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
    return 0;
}
/*

1 2
1 2
1 2
1 2
2 2
1 1

*/