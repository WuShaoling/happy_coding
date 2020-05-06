#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, D;
    cin >> n >> D;
    vector<pair<int, int>> A(n);  // 防御
    for (int i = 0; i < n; i++) cin >> A[i].first;
    for (int i = 0; i < n; i++) cin >> A[i].second;

    sort(A.begin(), A.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             if (a.first == b.first) {
                 return a.second < b.second;
             }
             return a.first < b.first;
         });

    

    for (pair<int, int> p : A) {
        cout << p.first << " -> " << p.second << endl;
    }
    return 0;
}
/*

3 50
100 50 50
1000 1001 1000

*/